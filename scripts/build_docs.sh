#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "${ROOT_DIR}"

BUILD_TOOLS_DIR="${ROOT_DIR}/build/tools"
mkdir -p "${BUILD_TOOLS_DIR}"

# 1. Check or install doxybook2
DOXYBOOK2="doxybook2"
if ! command -v doxybook2 &>/dev/null; then
    if [[ ! -x "${BUILD_TOOLS_DIR}/bin/doxybook2" && ! -x "${BUILD_TOOLS_DIR}/doxybook2" ]]; then
        echo "==> doxybook2 not found in PATH. Downloading standalone binary to ${BUILD_TOOLS_DIR}..."
        DOXYBOOK2_URL="https://github.com/matusnovak/doxybook2/releases/download/v1.5.0/doxybook2-linux-amd64-v1.5.0.zip"
        curl -fsSL -o "${BUILD_TOOLS_DIR}/doxybook2.zip" "${DOXYBOOK2_URL}"
        unzip -q -o "${BUILD_TOOLS_DIR}/doxybook2.zip" -d "${BUILD_TOOLS_DIR}/"
        chmod +x "${BUILD_TOOLS_DIR}/bin/doxybook2" 2>/dev/null || chmod +x "${BUILD_TOOLS_DIR}/doxybook2"
        rm -f "${BUILD_TOOLS_DIR}/doxybook2.zip"
    fi
    if [[ -x "${BUILD_TOOLS_DIR}/bin/doxybook2" ]]; then
        DOXYBOOK2="${BUILD_TOOLS_DIR}/bin/doxybook2"
    else
        DOXYBOOK2="${BUILD_TOOLS_DIR}/doxybook2"
    fi
fi

# 2. Check or download doxygen
DOXYGEN="doxygen"
if ! command -v doxygen &>/dev/null; then
    DOXYGEN_DIR="${BUILD_TOOLS_DIR}/doxygen-1.18.0"
    if [[ ! -x "${DOXYGEN_DIR}/bin/doxygen" ]]; then
        echo "==> doxygen not found in PATH. Downloading standalone binary to ${BUILD_TOOLS_DIR}..."
        DOXYGEN_URL="https://github.com/doxygen/doxygen/releases/download/Release_1_18_0/doxygen-1.18.0.linux.bin.tar.gz"
        curl -fsSL "${DOXYGEN_URL}" | tar -xz -C "${BUILD_TOOLS_DIR}"
    fi
    DOXYGEN="${DOXYGEN_DIR}/bin/doxygen"
fi

echo "==> Running Doxygen..."
mkdir -p build/docs/doxygen
"${DOXYGEN}" Doxyfile

echo "==> Running Doxybook2 to generate Markdown in docs/api..."
mkdir -p docs/api
"${DOXYBOOK2}" -i build/docs/doxygen/xml -o docs/api -c doxybook2.json

echo "==> Building MkDocs site..."
if command -v mkdocs &>/dev/null; then
    mkdocs build
    echo "==> Documentation build complete in ./site/"
else
    echo "mkdocs is not installed in current environment. Install via:"
    echo "  pip install mkdocs-material pymdown-extensions"
fi
