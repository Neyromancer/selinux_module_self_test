/// \file selinux_self_test_engine.cpp
/// \brief
/// \author Dmitry Kormulev <kormulev@fintech.ru>
/// \version 1.0.0.0
/// \date 22.01.2019

#include "selinux_self_test_engine.h"

#include <iostream>

namespace fintech {
namespace security_self_tests {
void SelinuxSelfTestEngine::ProcessSelinuxSelfTest() {
  selinux_config_test_ = std::make_unique<SelinuxSelfTestParser>();
  selinux_config_test_->SetPath("/etc/security_self_test/global_selinux_self_test.conf");
  selinux_config_test_->ParseConfigFile();
  for (const auto &el : selinux_config_test_->GetLstFile())
    std::cout << el << std::endl;
}
}
}
