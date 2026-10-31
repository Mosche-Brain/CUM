cmake_minimum_required(VERSION 3.18)

if(CMAKE_HOST_WIN32)
    find_package(oneDPLWindowsIntelLLVM QUIET)
endif()

set(CUM_VERSION "0.1.6.7" CACHE STRING "CUM package version")
project(cum LANGUAGES CXX C VERSION ${CUM_VERSION})

option(CUM_PORTABLE_INSTALL
    "Omit build-host paths from installed RPATH and CMake package configs"
    OFF
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

if(WIN32)
    set(_cum_default_shared OFF)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
    add_compile_options(-Wno-error=return-type)
else()
    set(_cum_default_shared ON)
endif()

option(CUM_BUILD_SHARED "Build CUM library as shared library" ${_cum_default_shared})
if(CUM_BUILD_SHARED)
    set(CUM_LIBRARY_TYPE SHARED)
else()
    set(CUM_LIBRARY_TYPE STATIC)
endif()

option(BUILD_USE_MKL "Build CUM library using Intel oneMKL" ON)
option(BUILD_USE_CBLAS "Build CUM library using CBLAS" OFF)
option(BUILD_USE_NONE "Build CUM library using only plain C++" OFF)

set(CUM_BACKEND_COUNT 0)
if(BUILD_USE_MKL)
    math(EXPR CUM_BACKEND_COUNT "${CUM_BACKEND_COUNT}+1")
endif()
if(BUILD_USE_CBLAS)
    math(EXPR CUM_BACKEND_COUNT "${CUM_BACKEND_COUNT}+1")
endif()
if(BUILD_USE_NONE)
    math(EXPR CUM_BACKEND_COUNT "${CUM_BACKEND_COUNT}+1")
endif()
if(CUM_BACKEND_COUNT GREATER 1)
    message(FATAL_ERROR
        "BUILD_USE_MKL, BUILD_USE_CBLAS and BUILD_USE_NONE are mutually exclusive"
    )
endif()

if(NOT BUILD_USE_MKL AND NOT BUILD_USE_CBLAS AND NOT BUILD_USE_NONE)
    set(BUILD_USE_NONE ON)
endif()

# Exactly one numeric type may be selected. FP32 is the default.
option(CUM_USE_FP32 "Use single precision floating point" ON)
option(CUM_USE_FP64 "Use double precision floating point" OFF)
option(CUM_USE_FP16 "Use half precision floating point" OFF)
option(CUM_USE_BF16 "Use bfloat16 precision floating point" OFF)
option(CUM_USE_INT8 "Use int8 precision integer" OFF)

set(CUM_TYPE_COUNT 0)
if(CUM_USE_FP32)
    math(EXPR CUM_TYPE_COUNT "${CUM_TYPE_COUNT}+1")
endif()
if(CUM_USE_FP64)
    math(EXPR CUM_TYPE_COUNT "${CUM_TYPE_COUNT}+1")
endif()
if(CUM_USE_FP16)
    math(EXPR CUM_TYPE_COUNT "${CUM_TYPE_COUNT}+1")
endif()
if(CUM_USE_BF16)
    math(EXPR CUM_TYPE_COUNT "${CUM_TYPE_COUNT}+1")
endif()
if(CUM_USE_INT8)
    math(EXPR CUM_TYPE_COUNT "${CUM_TYPE_COUNT}+1")
endif()
if(CUM_TYPE_COUNT EQUAL 0)
    set(CUM_USE_FP32 ON)
    set(CUM_TYPE_COUNT 1)
endif()
if(CUM_TYPE_COUNT GREATER 1)
    message(FATAL_ERROR
        "CUM_USE_FP32, CUM_USE_FP64, CUM_USE_FP16, CUM_USE_BF16 and CUM_USE_INT8 are mutually exclusive"
    )
endif()

set(CUM_USE_MKL ${BUILD_USE_MKL})

set(CUM_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(CUM_GENERATED_INCLUDE_DIR "${CMAKE_CURRENT_BINARY_DIR}/generated")
set(CUM_PROJECT_NAME cum)

set(CUM_THIRDPARTY_DIR
    "${CMAKE_CURRENT_LIST_DIR}/thirdparty"
    CACHE PATH "CUM third-party dependency root"
)
set(CUM_ONEDNN_ROOT
    "${CUM_THIRDPARTY_DIR}/oneDNN"
    CACHE PATH "oneDNN source and install root"
)
set(CUM_ONEDNN_INSTALL_DIR
    "${CUM_ONEDNN_ROOT}/install"
    # "/home/jaro/Libraries/oneDNN/" # for development
    CACHE PATH "oneDNN installation prefix"
)


configure_file(
    "${CUM_SOURCE_DIR}/config.hpp.in"
    "${CUM_GENERATED_INCLUDE_DIR}/cum/config.hpp"
)

add_subdirectory(sources)

option(BUILD_C_BINDING "Build the C language binding" ON)
if(BUILD_C_BINDING)
    add_subdirectory(bindings/C)
endif()

option(BUILD_TESTS "Build CUM unit tests" ON)
if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
    if(BUILD_C_BINDING)
        add_subdirectory(bindings/C/tests)
    endif()
endif()

if(BUILD_USE_MKL)
    add_executable(example examples/test.cpp)
    target_link_libraries(example PRIVATE cum::cum)
endif()
