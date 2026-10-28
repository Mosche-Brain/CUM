add_executable(cum_C_test c_binding.c)
set_target_properties(cum_C_test PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(cum_C_test PRIVATE cum::C cum::cum m)
add_test(NAME c_binding COMMAND cum_C_test)
