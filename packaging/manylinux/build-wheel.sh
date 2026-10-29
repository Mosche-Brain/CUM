#!/usr/bin/env bash
# Builds CUM (icpx), installs it to a temporary prefix, packs it into the `cumpy` wheel and runs
# `auditwheel repair`. Executed inside the `builder` stage of packaging/manylinux/Dockerfile.
#
# Environment:
#   PLAT          manylinux platform tag            (default: manylinux_2_28_x86_64)
#   BUNDLE_INTEL  1 = also graft Intel/oneTBB runtime libraries into the wheel (very large),
#                 0 = leave them as external dependencies of the wheel   (default: 0)
set -euo pipefail

PLAT="${PLAT:-manylinux_2_28_x86_64}"
BUNDLE_INTEL="${BUNDLE_INTEL:-0}"
WORK=/tmp/work
OUT=/out

# shellcheck disable=SC1091
source /opt/intel/oneapi/setvars.sh --force > /dev/null

TOOLCHAIN_FLAG="--gcc-toolchain=${GCC_TOOLSET_ROOT}"

rm -rf "${WORK}"
mkdir -p "${WORK}" "${OUT}"

echo "==> Configuring CUM"
cmake -S /src -B "${WORK}/build" -G Ninja \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_C_COMPILER=icx -DCMAKE_CXX_COMPILER=icpx \
    -DCMAKE_C_FLAGS="${TOOLCHAIN_FLAG}" \
    -DCMAKE_CXX_FLAGS="${TOOLCHAIN_FLAG}" \
    -DCMAKE_C_COMPILER_LAUNCHER=ccache -DCMAKE_CXX_COMPILER_LAUNCHER=ccache \
    -DCUM_ONEDNN_INSTALL_DIR="${CUM_ONEDNN_INSTALL_DIR}" \
    -DBUILD_USE_MKL=ON -DBUILD_C_BINDING=ON -DBUILD_TESTS=OFF

echo "==> Building CUM"
cmake --build "${WORK}/build" --target cum_Core cum_MKL cum_C

echo "==> Installing CUM to ${WORK}/install"
cmake --install "${WORK}/build" --prefix "${WORK}/install"

echo "==> Building the cumpy wheel"
CUM_PREFIX="${WORK}/install" python -m pip wheel /src/bindings/python \
    --no-deps --no-build-isolation -w "${WORK}/wheelhouse"

WHEEL=$(ls "${WORK}"/wheelhouse/cumpy-*.whl)

echo "==> Symbols required by the wheel"
auditwheel show "${WHEEL}" || true

EXCLUDES=()
if [[ "${BUNDLE_INTEL}" != "1" ]]; then
    # Runtime provided by oneAPI / PyPI packages on the target machine.
    for pattern in 'libsycl.so*' 'libur_loader.so*' 'libur_adapter_*.so*' 'libumf.so*' \
                   'libmkl_*.so*' 'libtbb*.so*' 'libiomp5.so' \
                   'libimf.so' 'libsvml.so' 'libirng.so' 'libintlc.so*' 'libOpenCL.so*'; do
        EXCLUDES+=(--exclude "${pattern}")
    done
fi

echo "==> auditwheel repair (${PLAT})"
auditwheel repair --plat "${PLAT}" "${EXCLUDES[@]}" -w "${OUT}" "${WHEEL}"

echo "==> Done:"
ls -lh "${OUT}"/cumpy-*.whl
