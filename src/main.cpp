/// \file main.cpp
/// \brief
/// \author Dmitry Kormulev <kormulev@fintech.ru>
/// \version 1.0.0.0
/// \date 11.12.2018

#include <cstdlib>
#include <iostream>

#include "./selinux_module_test/selinux_module_test.h"
#include "./selinux_type_test/selinux_type_test.h"
#include "./selinux_pam_test/selinux_pam_test.h"
#include "./selinux_version_test/selinux_version_test.h"
#include "./selinux_config_test/selinux_config_test.h"
#include "./selinux_config_sysconfig_selinux_test/selinux_config_sysconfig_selinux_test.h"

int main(void) {
  // fintech::security_self_tests::SelinuxModuleTest semodule_test;
  // fintech::security_self_tests::SelinuxPamTest semodule_test;
  //fintech::security_self_tests::SelinuxVersionTest seversion_test;
  fintech::security_self_tests::SelinuxConfigSysconfigSelinuxTest seconfig_test;
  std::cout << "parse function just about to start" << std::endl;
  seconfig_test.SetPath("/etc/sysconfig/selinux");
  seconfig_test.ParseConfigFile();
  seconfig_test.Print();
  //seversion_test.SetSelinuxVersion();
  //seversion_test.PrintSelinuxVersion();

  return EXIT_SUCCESS;
}
