# Building & Publishing the `cumpy` `manylinux_2_28` Wheel

## 1. GitHub Actions CI/CD (Recommended)

The workflow [`.github/workflows/python-wheels.yml`](../../.github/workflows/python-wheels.yml) builds, repairs, tests, and publishes `cumpy-*-manylinux_2_28_x86_64.whl` in the cloud:

1. **`build-wheel`**:
   - Runs `quay.io/pypa/manylinux_2_28_x86_64` with `gcc-toolset-14` (`libstdc++_nonshared.a` + `libstdc++exp.a` for C++23 `std::println`) and Intel oneAPI 2026.x.
   - Caches the static `oneDNN` installation (`.cache/onednn-install`, keyed by the `thirdparty/oneDNN` submodule SHA) and `ccache` via `actions/cache@v4`, so `oneDNN` is compiled only once per submodule update.
   - Runs [`build-wheel.sh`](./build-wheel.sh) to compile `libcum_Core.so`, `libcum_MKL.so`, and `libcum_C.so`, repair the wheel with `auditwheel repair --plat manylinux_2_28_x86_64`, and inject `$ORIGIN:$ORIGIN/../../..:$ORIGIN/../../../../lib` into `RUNPATH` so `ld-linux` resolves Intel runtime libraries installed by `pip` into `<prefix>/lib`.
2. **`test-wheel`**:
   - Installs the wheel on clean `ubuntu-latest` VMs (without `/opt/intel/oneapi`) across Python 3.10, 3.12, and 3.13, pulling Intel runtime dependencies (`dpcpp-cpp-rt`, `mkl`, `onemkl-sycl-{blas,rng,vm}`, `intel-opencl-rt`, `intel-cmplr-lib-rt`, `tbb`, `umf`) from PyPI and running the `cumpy` test suite.
3. **`publish-pypi`**:
   - Triggered automatically when pushing a version tag matching `v*` (e.g. `git tag v0.1.5.1 && git push origin v0.1.5.1`).
   - Uses PyPI **Trusted Publishing (OIDC)** (`environment: pypi`) — configure a Trusted Publisher on PyPI pointing to repository owner/name, workflow `python-wheels.yml`, and environment `pypi`.

---

## 2. Local Container Build (Optional)

You can also run the same build locally using `podman` (preferred) or `docker` with `buildx`:

```bash
packaging/manylinux/build.sh                  # -> dist/cumpy-*-manylinux_2_28_x86_64.whl
BUNDLE_INTEL=1 packaging/manylinux/build.sh   # also bundle Intel/oneTBB runtime into the wheel (very large)
```

| Stage | Contents | Rebuilt when |
|---|---|---|
| `oneapi` | GCC toolset 14, cmake/ninja, Intel oneAPI (compiler, MKL, oneDPL, oneTBB) | `Dockerfile` changes |
| `onednn` | Static oneDNN in `/opt/onednn` | `thirdparty/oneDNN` or its flags change |
| `builder` | CUM sources + `build-wheel.sh` | Any source change |
