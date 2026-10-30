cmake_minimum_required(VERSION 3.18)
project(cumpy LANGUAGES C CXX VERSION 0.1.0)

set(CUMPY_PACKAGE_DIR "cumpy")

# 1. If CUM_PREFIX is provided (or already built in /tmp/cuminstall), bundle from there.
# 2. Otherwise build CUM + cum_C directly from the repository root.
set(CUM_ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../..")

if(DEFINED ENV{CUM_PREFIX} AND NOT CUM_PREFIX)
    set(CUM_PREFIX "$ENV{CUM_PREFIX}")
endif()

if(CUM_PREFIX)
    foreach(_libdir IN ITEMS lib lib64)
        if(EXISTS "${CUM_PREFIX}/${_libdir}/libcum_C.so")
            set(_cum_found_libdir "${CUM_PREFIX}/${_libdir}")
            break()
        endif()
    endforeach()
endif()

if(_cum_found_libdir)
    message(STATUS "Bundling pre-installed CUM libraries from ${_cum_found_libdir}")
    file(GLOB _cum_libs "${_cum_found_libdir}/libcum*.so*")
    install(FILES ${_cum_libs} DESTINATION "${CUMPY_PACKAGE_DIR}")
else()
    set(BUILD_TESTS OFF CACHE BOOL "" FORCE)
    set(BUILD_C_BINDING ON CACHE BOOL "" FORCE)
    set(CUM_BUILD_SHARED ON CACHE BOOL "" FORCE)
    set(CUM_C_BUILD_SHARED ON CACHE BOOL "" FORCE)
    set(CMAKE_INSTALL_LIBDIR "${CUMPY_PACKAGE_DIR}" CACHE STRING "" FORCE)
    set(CMAKE_INSTALL_RPATH "$ORIGIN")
    add_subdirectory("${CUM_ROOT_DIR}" "${CMAKE_CURRENT_BINARY_DIR}/cum_build")
endif()
