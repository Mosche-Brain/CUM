add_library(cum_C STATIC
    src/cum.cpp
    src/tensor.cpp
    src/matrix.cpp
    src/vector.cpp
)

set_target_properties(cum_C PROPERTIES
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED ON
    POSITION_INDEPENDENT_CODE ON
)

target_include_directories(cum_C
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(cum_C
    PRIVATE
        cum::cum
)

add_library(cum::C ALIAS cum_C)
