# syntax=docker/dockerfile:1.6
#
# Builds the `cumpy` wheel (CUM + C binding + Python binding) inside a manylinux image, so that the
# resulting libraries only require an old glibc and `auditwheel repair` can assign a manylinux tag.
#
# Build context: the repository root.
#
#   docker build -f packaging/manylinux/Dockerfile -t cum-manylinux .
#   docker run --rm --user "$(id -u):$(id -g)" -v "$PWD/dist:/out" cum-manylinux
#
# Layers are ordered from the least to the most frequently changing one, so the expensive ones
# (oneAPI installation, static oneDNN) are served from the Docker cache until their inputs change.

ARG MANYLINUX_IMAGE=quay.io/pypa/manylinux_2_28_x86_64

# ----------------------------------------------------------------------------------------------
# 1. Toolchain: GCC toolset (C++23 / std::println), build tools and Intel oneAPI
# ----------------------------------------------------------------------------------------------
FROM ${MANYLINUX_IMAGE} AS oneapi

ARG GCC_TOOLSET=14
ENV GCC_TOOLSET_ROOT=/opt/rh/gcc-toolset-${GCC_TOOLSET}/root/usr

RUN dnf install -y gcc-toolset-${GCC_TOOLSET} ccache \
    && dnf clean all

RUN /opt/python/cp312-cp312/bin/pip install --no-cache-dir cmake ninja scikit-build-core build

RUN <<'EOF'
#!/bin/bash
cat > /etc/yum.repos.d/oneAPI.repo <<'REPO'
[oneAPI]
name=Intel(R) oneAPI repository
baseurl=https://yum.repos.intel.com/oneapi
enabled=1
gpgcheck=1
repo_gpgcheck=1
gpgkey=https://yum.repos.intel.com/intel-gpg-keys/GPG-PUB-KEY-INTEL-SW-PRODUCTS.PUB
REPO
EOF

# Pin the versions here (e.g. intel-oneapi-compiler-dpcpp-cpp-2026.0) for reproducible images.
RUN dnf install -y \
        intel-oneapi-compiler-dpcpp-cpp \
        intel-oneapi-mkl-devel \
        intel-oneapi-onedpl-devel \
        intel-oneapi-tbb-devel \
    && dnf clean all

ENV PATH=/opt/python/cp312-cp312/bin:${PATH}

# ----------------------------------------------------------------------------------------------
# 2. Static oneDNN (the slowest step). Rebuilt only when thirdparty/oneDNN or the flags change.
#    The flags must be kept in sync with sources/Backends/MKL/CMakeLists.txt.
# ----------------------------------------------------------------------------------------------
FROM oneapi AS onednn

COPY thirdparty/oneDNN /src/oneDNN

RUN --mount=type=cache,target=/root/.ccache <<'EOF'
#!/bin/bash
set -ex
if [[ -f /opt/rh/gcc-toolset-14/enable ]]; then
    source /opt/rh/gcc-toolset-14/enable
fi
source /opt/intel/oneapi/setvars.sh --force
set -u
cmake -S /src/oneDNN -B /tmp/onednn-build -G Ninja \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_C_COMPILER=icx -DCMAKE_CXX_COMPILER=icpx \
    -DCMAKE_C_FLAGS="--gcc-toolchain=${GCC_TOOLSET_ROOT}" \
    -DCMAKE_CXX_FLAGS="--gcc-toolchain=${GCC_TOOLSET_ROOT}" \
    -DCMAKE_C_COMPILER_LAUNCHER=ccache -DCMAKE_CXX_COMPILER_LAUNCHER=ccache \
    -DCMAKE_POSITION_INDEPENDENT_CODE=ON \
    -DCMAKE_INSTALL_PREFIX=/opt/onednn -DCMAKE_INSTALL_LIBDIR=lib \
    -DONEDNN_LIBRARY_TYPE=STATIC \
    -DONEDNN_CPU_RUNTIME=SYCL -DONEDNN_GPU_RUNTIME=SYCL -DONEDNN_GPU_VENDOR=INTEL \
    -DONEDNN_BUILD_TESTS=OFF -DONEDNN_BUILD_EXAMPLES=OFF -DONEDNN_BUILD_DOC=OFF
cmake --build /tmp/onednn-build --target install
rm -rf /tmp/onednn-build
EOF

# ----------------------------------------------------------------------------------------------
# 3. CUM + wheel. Runs at `docker run` time; the wheel is written to /out.
# ----------------------------------------------------------------------------------------------
FROM oneapi AS builder

COPY --from=onednn /opt/onednn /opt/onednn
COPY . /src
COPY packaging/manylinux/build-wheel.sh /usr/local/bin/build-wheel.sh

ENV HOME=/tmp \
    CCACHE_DIR=/ccache \
    CUM_ONEDNN_INSTALL_DIR=/opt/onednn

VOLUME ["/out", "/ccache"]
ENTRYPOINT ["/usr/local/bin/build-wheel.sh"]
