add_library(selinux_self_test_engine STATIC selinux_self_test_engine.cpp)
target_link_libraries(selinux_self_test_engine selinux_config_test
selinux_module_test selinux_pam_test selinux_type_test selinux_version_test)
