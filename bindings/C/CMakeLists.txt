# The C binding can be built either as a part of the main CUM project or standalone against an
# installed CUM (find_package(cum)). The standalone mode does not need -fsycl, so any C++23
# compiler (GCC 13+, Clang) can be used:
#
#   cmake -S bindings/C -B build-c -DCMAKE_PREFIX_PATH=<cum install prefix>
#
if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    cmake_minimum_required(VERSION 3.14)
    project(cum_C LANGUAGES C CXX VERSION 0.1)

    set(CMAKE_CXX_STANDARD 23)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_C_STANDARD 23)
    set(CMAKE_C_STANDARD_REQUIRED ON)

    option(BUILD_TESTS "Build the C binding tests" ON)

    set(CUM_C_STANDALONE ON)
    find_package(cum CONFIG REQUIRED)
endif()

include(GNUInstallDirs)

option(CUM_C_BUILD_SHARED "Build the C binding as a shared library" ON)
if(CUM_C_BUILD_SHARED)
    set(CUM_C_LIBRARY_TYPE SHARED)
else()
    set(CUM_C_LIBRARY_TYPE STATIC)
endif()

add_library(cum_C ${CUM_C_LIBRARY_TYPE}
    src/cum.cpp
    src/tensor.cpp
    src/matrix.cpp
    src/vector.cpp
    src/event.cpp
    src/blas.cpp
    src/neural_primitives.cpp
)

set_target_properties(cum_C PROPERTIES
    EXPORT_NAME C
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED ON
    POSITION_INDEPENDENT_CODE ON
    CXX_VISIBILITY_PRESET hidden
    VISIBILITY_INLINES_HIDDEN ON
    INSTALL_RPATH "$ORIGIN"
    INSTALL_RPATH_USE_LINK_PATH FALSE
)

if(CUM_C_BUILD_SHARED)
    target_compile_definitions(cum_C PRIVATE CUM_C_BUILDING)
else()
    target_compile_definitions(cum_C PUBLIC CUM_C_STATIC_DEFINE)
endif()

target_include_directories(cum_C
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_link_libraries(cum_C
    PRIVATE
        cum::cum
)

add_library(cum::C ALIAS cum_C)

if(CUM_C_STANDALONE)
    if(BUILD_TESTS)
        enable_testing()
        add_subdirectory(tests)
    endif()
endif()

install(TARGETS cum_C
        EXPORT cumCTargets
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
install(EXPORT cumCTargets
        FILE cumCTargets.cmake
        NAMESPACE cum::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/cum)
install(DIRECTORY include/cum DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        FILES_MATCHING PATTERN "*.h")
