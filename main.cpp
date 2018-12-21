/// \file main.cpp
/// \brief
/// \author Dmitry Kormulev <kormulev@fintech.ru>
/// \version 1.0.0.0
/// \date 11.12.2018

#include <cstdlib>
#include <iostream>

#include "selinux_module_test.h"
#include "selinux_type_test.h"
#include "selinux_pam_test.h"
#include "selinux_version_test.h"

int main(void) {
  // fintech::security_self_tests::SelinuxModuleTest semodule_test;
  // fintech::security_self_tests::SelinuxPamTest semodule_test;
  fintech::security_self_tests::SelinuxVersionTest seversion_test;
  std::cout << "parse function just about to start" << std::endl;
  seversion_test.SetSelinuxVersion();
  seversion_test.PrintSelinuxVersion();

  return EXIT_SUCCESS;
}
