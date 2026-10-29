# Building the `cumpy` wheel in a manylinux container

`build.sh` builds the whole stack (static oneDNN, CUM, C binding, Python wheel) inside
`quay.io/pypa/manylinux_2_28_x86_64` (glibc 2.28), so the libraries do not reference newer glibc
symbols (e.g. `GLIBC_2.38`) and `auditwheel repair` can assign the `manylinux_2_28` tag.

```bash
packaging/manylinux/build.sh                  # -> dist/cumpy-*-manylinux_2_28_x86_64.whl
BUNDLE_INTEL=1 packaging/manylinux/build.sh   # also bundle Intel/oneTBB runtime (very large)
```

Requirements: `podman` (preferred) or `docker` with the buildx plugin. The legacy `docker build`
builder is not enough (the Dockerfile uses heredocs and `RUN --mount=type=cache`).

## Layers and caching

| Stage | Contents | Rebuilt when |
|---|---|---|
| `oneapi` | GCC toolset 14, cmake/ninja, Intel oneAPI (compiler, MKL, oneDPL, oneTBB) | the Dockerfile changes |
| `onednn` | static oneDNN in `/opt/onednn` (slowest step) | `thirdparty/oneDNN` or its flags change |
| `builder` | CUM sources + `build-wheel.sh` | any source change |

The CUM build itself runs at `run` time. Its ccache lives in the `cum-ccache` volume. The oneDNN
flags in the Dockerfile must be kept in sync with `sources/Backends/MKL/CMakeLists.txt`.
Do not reuse a oneDNN built on the host: it was compiled against a newer glibc.

## What goes into the wheel

By default the Intel runtime (`libsycl`, `libmkl_*`, `libtbb`, `libumf`, `libimf`, ...) is excluded
from `auditwheel repair`, so the wheel contains only `libcum_*.so` and expects the oneAPI runtime
on the target machine (its location must be reachable by the dynamic loader). `BUNDLE_INTEL=1`
grafts everything, which makes the wheel far larger than PyPI's default 100 MB limit.

## Known open points

- The build was not run end to end yet. The first run downloads several GB of oneAPI and compiles
  oneDNN for a while.
- `std::println` in `Tensor.cpp` and `internal/context.cpp` needs `GLIBCXX` symbols newer than
  the manylinux_2_28 policy allows. GCC toolset links such symbols statically via
  `libstdc++_nonshared.a`; if `auditwheel` still reports `GLIBCXX`, replace those calls or link
  `libcum_MKL.so` with `-static-libstdc++ -static-libgcc`.
