#!/usr/bin/env bash
# Host-side helper: builds the manylinux image and the wheel into ./dist.
#
#   packaging/manylinux/build.sh                 # wheel without bundled Intel runtime
#   BUNDLE_INTEL=1 packaging/manylinux/build.sh  # wheel with bundled Intel runtime (huge)
#
# Container engine: podman when available, otherwise docker (which needs the buildx plugin,
# because the Dockerfile uses heredocs and cache mounts). Override with ENGINE=docker|podman.
set -euo pipefail

cd "$(dirname "$0")/../.."

IMAGE="${IMAGE:-cum-manylinux}"
ENGINE="${ENGINE:-$(command -v podman > /dev/null && echo podman || echo docker)}"
mkdir -p dist

"${ENGINE}" build -f packaging/manylinux/Dockerfile -t "${IMAGE}" .

RUN_ARGS=(--rm -e PLAT -e BUNDLE_INTEL -v "$PWD/dist:/out" -v cum-ccache:/ccache)
if [[ "${ENGINE}" == "docker" ]]; then
    # Rootful docker: write the wheel as the invoking user. Rootless podman already maps the
    # container root to the invoking user.
    RUN_ARGS+=(--user "$(id -u):$(id -g)")
fi

"${ENGINE}" run "${RUN_ARGS[@]}" "${IMAGE}"
