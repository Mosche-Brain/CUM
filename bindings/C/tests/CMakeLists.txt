add_executable(cum_C_test c_binding.c)
target_link_libraries(cum_C_test PRIVATE cum::C m)
add_test(NAME c_binding COMMAND cum_C_test)
