add_library(selinux_config_test STATIC selinux_config_test.cpp)
target_link_libraries(selinux_config_test selinux_system_test)
