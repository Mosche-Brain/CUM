#!/usr/bin/env bash
# Builds CUM (icpx), installs it to a temporary prefix, packs it into the `cumpy` wheel and runs
# `auditwheel repair`. Works both inside `packaging/manylinux/Dockerfile` and directly in CI
# (`quay.io/pypa/manylinux_2_28_x86_64`).
#
# Environment:
#   PLAT                    manylinux platform tag            (default: manylinux_2_28_x86_64)
#   BUNDLE_INTEL            1 = graft Intel/oneTBB libs into the wheel (very large),
#                           0 = use Intel runtime wheels from PyPI     (default: 0)
#   SRC_DIR                 repository root                   (default: /src)
#   OUT_DIR                 output wheel directory            (default: /out)
#   WORK_DIR                scratch build directory           (default: /tmp/work)
#   CUM_ONEDNN_INSTALL_DIR  static oneDNN install prefix      (default: /opt/onednn)
#   GCC_TOOLSET_ROOT        Red Hat GCC toolset prefix        (default: /opt/rh/gcc-toolset-14/root/usr)
#   PYTHON_BIN              Python interpreter for wheel build (default: /opt/python/cp312-cp312/bin/python)
set -euo pipefail

PLAT="${PLAT:-manylinux_2_28_x86_64}"
BUNDLE_INTEL="${BUNDLE_INTEL:-0}"
SRC_DIR="${SRC_DIR:-/src}"
OUT_DIR="${OUT_DIR:-/out}"
WORK_DIR="${WORK_DIR:-/tmp/work}"
CUM_ONEDNN_INSTALL_DIR="${CUM_ONEDNN_INSTALL_DIR:-/opt/onednn}"
GCC_TOOLSET_ROOT="${GCC_TOOLSET_ROOT:-/opt/rh/gcc-toolset-14/root/usr}"
PYTHON_BIN="${PYTHON_BIN:-/opt/python/cp312-cp312/bin/python}"

# Enable Red Hat gcc-toolset and Intel oneAPI (both scripts reference unset vars, so disable -u).
set +u
if [[ -f /opt/rh/gcc-toolset-14/enable ]]; then
    # shellcheck disable=SC1091
    source /opt/rh/gcc-toolset-14/enable
fi

# shellcheck disable=SC1091
source /opt/intel/oneapi/setvars.sh --force > /dev/null
set -u

PYTHON_DIR="$(dirname "${PYTHON_BIN}")"
export PATH="${PYTHON_DIR}:${PATH}"

TOOLCHAIN_FLAG="--gcc-toolchain=${GCC_TOOLSET_ROOT}"

rm -rf "${WORK_DIR}"
mkdir -p "${WORK_DIR}" "${OUT_DIR}"

if [[ ! -f "${CUM_ONEDNN_INSTALL_DIR}/lib/libdnnl.a" && ! -f "${CUM_ONEDNN_INSTALL_DIR}/lib64/libdnnl.a" ]]; then
    echo "==> Static oneDNN not found in ${CUM_ONEDNN_INSTALL_DIR}; building from ${SRC_DIR}/thirdparty/oneDNN"
    mkdir -p "${CUM_ONEDNN_INSTALL_DIR}"
    cmake -S "${SRC_DIR}/thirdparty/oneDNN" -B "${WORK_DIR}/onednn-build" -G Ninja \
        -DCMAKE_BUILD_TYPE=Release \
        -DCMAKE_C_COMPILER=icx -DCMAKE_CXX_COMPILER=icpx \
        -DCMAKE_C_FLAGS="${TOOLCHAIN_FLAG}" \
        -DCMAKE_CXX_FLAGS="${TOOLCHAIN_FLAG}" \
        -DCMAKE_C_COMPILER_LAUNCHER=ccache -DCMAKE_CXX_COMPILER_LAUNCHER=ccache \
        -DCMAKE_POSITION_INDEPENDENT_CODE=ON \
        -DCMAKE_INSTALL_PREFIX="${CUM_ONEDNN_INSTALL_DIR}" \
        -DCMAKE_INSTALL_LIBDIR=lib \
        -DONEDNN_LIBRARY_TYPE=STATIC \
        -DONEDNN_CPU_RUNTIME=SYCL \
        -DONEDNN_GPU_RUNTIME=SYCL \
        -DONEDNN_GPU_VENDOR=INTEL \
        -DONEDNN_BUILD_TESTS=OFF \
        -DONEDNN_BUILD_EXAMPLES=OFF \
        -DONEDNN_BUILD_DOC=OFF
    cmake --build "${WORK_DIR}/onednn-build" --target install
    rm -rf "${WORK_DIR}/onednn-build"
else
    echo "==> Using cached static oneDNN from ${CUM_ONEDNN_INSTALL_DIR}"
fi

echo "==> Configuring CUM"
cmake -S "${SRC_DIR}" -B "${WORK_DIR}/build" -G Ninja \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_INSTALL_LIBDIR=lib \
    -DCMAKE_C_COMPILER=icx -DCMAKE_CXX_COMPILER=icpx \
    -DCMAKE_C_FLAGS="${TOOLCHAIN_FLAG}" \
    -DCMAKE_CXX_FLAGS="${TOOLCHAIN_FLAG}" \
    -DCMAKE_C_COMPILER_LAUNCHER=ccache -DCMAKE_CXX_COMPILER_LAUNCHER=ccache \
    -DCUM_ONEDNN_INSTALL_DIR="${CUM_ONEDNN_INSTALL_DIR}" \
    -DBUILD_USE_MKL=ON -DBUILD_C_BINDING=ON -DBUILD_TESTS=OFF

echo "==> Building CUM"
cmake --build "${WORK_DIR}/build" --target cum_Core cum_MKL cum_C

echo "==> Installing CUM to ${WORK_DIR}/install"
cmake --install "${WORK_DIR}/build" --prefix "${WORK_DIR}/install"

# Strip any build-host `/opt/intel/oneapi/...` RPATH entries injected by MKLConfig.cmake before wheel packaging.
for so in "${WORK_DIR}"/install/lib/libcum*.so*; do
    [[ -L "${so}" ]] && continue
    patchelf --set-rpath '$ORIGIN' "${so}"
done

echo "==> Building the cumpy wheel"
CUM_PREFIX="${WORK_DIR}/install" "${PYTHON_BIN}" -m pip wheel "${SRC_DIR}/bindings/python" \
    --no-deps --no-build-isolation -w "${WORK_DIR}/wheelhouse"

WHEEL=$(ls "${WORK_DIR}"/wheelhouse/cumpy-*.whl)

echo "==> Symbols required by the raw wheel"
auditwheel show "${WHEEL}" || true

EXCLUDES=()
if [[ "${BUNDLE_INTEL}" != "1" ]]; then
    # Runtime provided by Intel / oneTBB / UMF / TCM PyPI packages on the target machine.
    for pattern in 'libsycl.so*' 'libur_loader.so*' 'libur_adapter_*.so*' 'libumf.so*' \
                   'libtcm*.so*' 'libhwloc.so*' \
                   'libmkl_*.so*' 'libtbb*.so*' 'libiomp5.so' \
                   'libimf.so' 'libsvml.so' 'libirng.so' 'libintlc.so*' 'libOpenCL.so*'; do
        EXCLUDES+=(--exclude "${pattern}")
    done
fi

echo "==> auditwheel repair (${PLAT})"
mkdir -p "${WORK_DIR}/repaired"
auditwheel repair --plat "${PLAT}" "${EXCLUDES[@]}" -w "${WORK_DIR}/repaired" "${WHEEL}"

REPAIRED_WHEEL=$(ls "${WORK_DIR}"/repaired/cumpy-*.whl)

if [[ "${BUNDLE_INTEL}" != "1" ]]; then
    echo "==> Setting RUNPATH on cumpy/libcum*.so* for pip-installed Intel runtime (<prefix>/lib)"
    "${PYTHON_BIN}" - "${REPAIRED_WHEEL}" "${OUT_DIR}" "${WORK_DIR}/repack" <<'PY'
import base64
import csv
import hashlib
import os
from pathlib import Path
import shutil
import subprocess
import sys
import zipfile

src_wheel = Path(sys.argv[1])
out_dir = Path(sys.argv[2])
unpack_dir = Path(sys.argv[3])
shutil.rmtree(unpack_dir, ignore_errors=True)
unpack_dir.mkdir(parents=True)

with zipfile.ZipFile(src_wheel, "r") as zf:
    for info in zf.infolist():
        target = unpack_dir / info.filename
        zf.extract(info, unpack_dir)
        mode = (info.external_attr >> 16) & 0o777
        if mode and not target.is_symlink():
            os.chmod(target, mode)

rpath = "$ORIGIN:$ORIGIN/../../..:$ORIGIN/../../../../lib"
for so in sorted((unpack_dir / "cumpy").glob("libcum*.so*")):
    if not so.is_symlink():
        subprocess.run(["patchelf", "--set-rpath", rpath, str(so)], check=True)

record_rel = next(p.relative_to(unpack_dir) for p in unpack_dir.glob("*.dist-info/RECORD"))
record_path = unpack_dir / record_rel

rows = []
for file_path in sorted(p for p in unpack_dir.rglob("*") if p.is_file()):
    rel = file_path.relative_to(unpack_dir).as_posix()
    if rel == record_rel.as_posix():
        continue
    data = file_path.read_bytes()
    digest = base64.urlsafe_b64encode(hashlib.sha256(data).digest()).rstrip(b"=").decode("ascii")
    rows.append([rel, f"sha256={digest}", str(len(data))])
rows.append([record_rel.as_posix(), "", ""])

with record_path.open("w", newline="", encoding="utf-8") as f:
    csv.writer(f, lineterminator="\n").writerows(rows)

dst_wheel = out_dir / src_wheel.name
with zipfile.ZipFile(dst_wheel, "w", compression=zipfile.ZIP_DEFLATED) as zf:
    for file_path in sorted(p for p in unpack_dir.rglob("*") if p.is_file()):
        rel = file_path.relative_to(unpack_dir).as_posix()
        st = file_path.stat()
        zi = zipfile.ZipInfo(rel)
        zi.compress_type = zipfile.ZIP_DEFLATED
        zi.external_attr = (st.st_mode & 0xFFFF) << 16
        zf.writestr(zi, file_path.read_bytes())
PY
else
    cp -f "${REPAIRED_WHEEL}" "${OUT_DIR}/"
fi

echo "==> Done:"
ls -lh "${OUT_DIR}"/cumpy-*.whl
