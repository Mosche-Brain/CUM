file(GLOB_RECURSE SOURCES_MKL CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.c"
)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

find_package(TBB CONFIG REQUIRED)
find_package(MKL CONFIG REQUIRED)
find_package(oneDPL CONFIG REQUIRED)

if(NOT EXISTS "${CUM_ONEDNN_INSTALL_DIR}/lib/cmake/dnnl/dnnl-config.cmake" AND
   NOT EXISTS "${CUM_ONEDNN_INSTALL_DIR}/lib64/cmake/dnnl/dnnl-config.cmake")
    if(NOT EXISTS "${CUM_ONEDNN_ROOT}/CMakeLists.txt")
        message(FATAL_ERROR
            "oneDNN installation was not found in '${CUM_ONEDNN_INSTALL_DIR}' and "
            "source submodule at '${CUM_ONEDNN_ROOT}' is missing. "
            "Initialize submodules with: git submodule update --init --recursive"
        )
    endif()

    message(STATUS "oneDNN not found in '${CUM_ONEDNN_INSTALL_DIR}'. Building from '${CUM_ONEDNN_ROOT}'...")

    include(ProcessorCount)
    ProcessorCount(CUM_ONEDNN_BUILD_JOBS)
    if(CUM_ONEDNN_BUILD_JOBS EQUAL 0)
        set(CUM_ONEDNN_BUILD_JOBS 4)
    endif()

    set(CUM_ONEDNN_C_COMPILER "${CMAKE_C_COMPILER}")
    if(CMAKE_CXX_COMPILER MATCHES "icpx$" AND NOT CMAKE_C_COMPILER MATCHES "icx$")
        get_filename_component(_cxx_compiler_dir "${CMAKE_CXX_COMPILER}" DIRECTORY)
        find_program(CUM_ICX_EXECUTABLE NAMES icx HINTS "${_cxx_compiler_dir}" NO_DEFAULT_PATH)
        if(NOT CUM_ICX_EXECUTABLE)
            find_program(CUM_ICX_EXECUTABLE NAMES icx)
        endif()
        if(CUM_ICX_EXECUTABLE)
            set(CUM_ONEDNN_C_COMPILER "${CUM_ICX_EXECUTABLE}")
        endif()
    endif()

    set(CUM_ONEDNN_BUILD_DIR "${CUM_ONEDNN_ROOT}/build")

    execute_process(
        COMMAND "${CMAKE_COMMAND}"
            -S "${CUM_ONEDNN_ROOT}"
            -B "${CUM_ONEDNN_BUILD_DIR}"
            -G "${CMAKE_GENERATOR}"
            "-DCMAKE_MAKE_PROGRAM=${CMAKE_MAKE_PROGRAM}"
            "-DCMAKE_C_COMPILER=${CUM_ONEDNN_C_COMPILER}"
            "-DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}"
            "-DCMAKE_BUILD_TYPE=Release"
            "-DCMAKE_INSTALL_PREFIX=${CUM_ONEDNN_INSTALL_DIR}"
            "-DCMAKE_INSTALL_LIBDIR=lib"
            "-DONEDNN_LIBRARY_TYPE=SHARED"
            "-DONEDNN_CPU_RUNTIME=SYCL"
            "-DONEDNN_GPU_RUNTIME=SYCL"
            "-DONEDNN_GPU_VENDOR=INTEL"
            "-DONEDNN_BUILD_TESTS=OFF"
            "-DONEDNN_BUILD_EXAMPLES=OFF"
            "-DONEDNN_BUILD_DOC=OFF"
        RESULT_VARIABLE _onednn_configure_result
    )
    if(NOT _onednn_configure_result EQUAL 0)
        message(FATAL_ERROR "Failed to configure oneDNN in '${CUM_ONEDNN_ROOT}'")
    endif()

    execute_process(
        COMMAND "${CMAKE_COMMAND}"
            --build "${CUM_ONEDNN_BUILD_DIR}"
            --config Release
            --target install
            --parallel ${CUM_ONEDNN_BUILD_JOBS}
        RESULT_VARIABLE _onednn_build_result
    )
    if(NOT _onednn_build_result EQUAL 0)
        message(FATAL_ERROR "Failed to build and install oneDNN into '${CUM_ONEDNN_INSTALL_DIR}'")
    endif()
endif()

find_package(dnnl CONFIG REQUIRED
    PATHS
        "${CUM_ONEDNN_INSTALL_DIR}/lib/cmake/dnnl"
        "${CUM_ONEDNN_INSTALL_DIR}/lib64/cmake/dnnl"
    NO_DEFAULT_PATH
)

add_library(${CUM_PROJECT_NAME}_MKL ${CUM_LIBRARY_TYPE}
    ${SOURCES_MKL}
)

set_target_properties(${CUM_PROJECT_NAME}_MKL PROPERTIES EXPORT_NAME MKL)

target_include_directories(${CUM_PROJECT_NAME}_MKL
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_definitions(${CUM_PROJECT_NAME}_MKL
    PRIVATE BUILD_USE_MKL
)

target_compile_options(${CUM_PROJECT_NAME}_MKL
    PRIVATE $<$<COMPILE_LANGUAGE:CXX>:-fsycl>
)

find_library(CUM_UMF_LIBRARY
    NAMES umf libumf.so.1
    PATHS
        "$ENV{UMF_ROOT}/lib"
        "$ENV{ONEAPI_ROOT}/umf/latest/lib"
        "/opt/intel/oneapi/umf/latest/lib"
)

target_link_libraries(${CUM_PROJECT_NAME}_MKL
    PUBLIC
        ${CUM_PROJECT_NAME}::Core
    PRIVATE
        TBB::tbb
        MKL::MKL
        MKL::MKL_DPCPP
        oneDPL
        DNNL::dnnl
)

if(CUM_UMF_LIBRARY)
    get_filename_component(CUM_UMF_LIBRARY_DIR "${CUM_UMF_LIBRARY}" REALPATH)
    get_filename_component(CUM_UMF_LIBRARY_DIR "${CUM_UMF_LIBRARY_DIR}" DIRECTORY)
    target_link_libraries(${CUM_PROJECT_NAME}_MKL
        PRIVATE
            "-Wl,--push-state,--no-as-needed"
            "${CUM_UMF_LIBRARY}"
            "-Wl,--pop-state"
    )
endif()

if(CUM_BUILD_SHARED)
    target_link_options(${CUM_PROJECT_NAME}_MKL PRIVATE -fsycl)
    set(_cum_mkl_rpath "$ORIGIN:${CMAKE_INSTALL_FULL_LIBDIR}")
    if(CUM_UMF_LIBRARY_DIR)
        list(APPEND _cum_mkl_rpath "${CUM_UMF_LIBRARY_DIR}")
    endif()
    set_target_properties(${CUM_PROJECT_NAME}_MKL PROPERTIES
        BUILD_RPATH "${CUM_UMF_LIBRARY_DIR}"
        INSTALL_RPATH "${_cum_mkl_rpath}"
        INSTALL_RPATH_USE_LINK_PATH TRUE
    )
else()
    target_link_options(${CUM_PROJECT_NAME}_MKL INTERFACE -fsycl)
endif()

add_library(${CUM_PROJECT_NAME}::MKL ALIAS ${CUM_PROJECT_NAME}_MKL)

install(TARGETS ${CUM_PROJECT_NAME}_MKL
    EXPORT cumTargets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(TARGET DNNL::dnnl)
    install(DIRECTORY "${CUM_ONEDNN_INSTALL_DIR}/lib/"
        DESTINATION ${CMAKE_INSTALL_LIBDIR}
        FILES_MATCHING
            PATTERN "libdnnl.so*"
    )
endif()
