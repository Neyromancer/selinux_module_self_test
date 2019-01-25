/// \file selinux_self_test_engine.cpp
/// \brief
/// \author Dmitry Kormulev <kormulev@fintech.ru>
/// \version 1.0.0.1
/// \date 22.01.2019

#include "selinux_self_test_engine.h"

extern "C" {
#include "unistd.h"
}

#include <iostream>

namespace fintech {
namespace security_self_tests {
void SelinuxSelfTestEngine::ProcessSelinuxSelfTests() {
  selinux_self_test_parser_.SetPath("/etc/security_self_test/global_selinux_self_test.conf");
  selinux_self_test_parser_.ParseConfigFile();
  if (!selinux_self_test_parser_.GetLstFile().empty()) {
    for (const auto &el : selinux_self_test_parser_.GetLstFile()) {
      usleep(10);
      selinux_config_test_.SetPath(el);
      std::cout << el << " is ";
      if (selinux_config_test_.IsConfigValid())
        std::cout << "not ";
      std::cout << "valid" << std::endl;
    }
  }
}
}
}
