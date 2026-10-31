# Getting Started

## Prerequisites

CUM is designed around modern C++ (C++20) and accelerated by Intel oneAPI:

- **C++ Compiler**: Intel DPC++/C++ Compiler (`icx` / `icpx`) or GCC 14+ / Clang 18+
- **Build System**: CMake 3.18+ and Ninja
- **Intel oneAPI Toolkits**:
    - Intel oneAPI Base Toolkit (oneMKL, oneDPL, oneTBB)
    - oneDNN (automatically fetched or built statically if missing)

---

## Building CUM from Source

### 1. Clone repository with submodules

```bash
git clone --recurse-submodules https://github.com/Mosche-Brain/CUM.git
cd CUM
```

### 2. Configure with CMake

Ensure your oneAPI environment variables are sourced:

```bash
source /opt/intel/oneapi/setvars.sh
```

Configure the project:

```bash
cmake -B build -G Ninja \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_C_COMPILER=icx \
    -DCMAKE_CXX_COMPILER=icpx \
    -DBUILD_TESTS=ON
```

### 3. Build & Run Tests

```bash
cmake --build build
ctest --test-dir build --output-on-failure
```

---

## Using CUM in CMake Projects

Once installed, CUM exports CMake targets:

```cmake
find_package(cum REQUIRED)

add_executable(my_app main.cpp)
target_link_libraries(my_app PRIVATE cum::cum)
```
