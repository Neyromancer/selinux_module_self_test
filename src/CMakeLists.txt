cmake_minimum_required (VERSION 3.8)
project (selinux_security_test)
set (CMAKE_CXX_STANDARD 11)
set (selinux_security_test_VERSION_MAJOR 1)
set (selinux_security_test_VERSION_MINOR 0)

include_directories ("${PROJECT_BINARY_DIR}")
include_directories ("${PROJECT_SOURCE_DIR}/selinux_system_test")
include_directories ("${PROJECT_SOURCE_DIR}/selinux_module_test")
include_directories ("${PROJECT_SOURCE_DIR}/selinux_pam_test")
include_directories ("${PROJECT_SOURCE_DIR}/selinux_type_test")
include_directories ("${PROJECT_SOURCE_DIR}/selinux_version_test")
include_directories ("${PROJECT_SOURCE_DIR}/selinux_config_test")
include_directories ("${PROJECT_SOURCE_DIR}/selinux_self_test_engine")
include_directories ("${PROJECT_SOURCE_DIR}/selinux_self_test_parser")

add_subdirectory (selinux_system_test)
add_subdirectory (selinux_module_test)
add_subdirectory (selinux_pam_test)
add_subdirectory (selinux_type_test)
add_subdirectory (selinux_version_test)
add_subdirectory (selinux_config_test)
add_subdirectory (selinux_self_test_engine)
add_subdirectory (selinux_self_test_parser)

add_executable (selinux_security_test main.cpp)
target_link_libraries(selinux_security_test selinux_system_test 
selinux_module_test selinux_pam_test selinux_type_test selinux_version_test
selinux_config_test selinux_self_test_engine selinux_self_test_parser)

install (TARGETS selinux_security_test DESTINATION ${PROJECT_BINARY_DIR})
