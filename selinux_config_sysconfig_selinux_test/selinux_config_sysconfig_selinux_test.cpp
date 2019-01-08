/// \file selinux_config_sysconfig_selinux_test.cpp
/// \brief
/// \author Dmitry Kormulev <kormulev@fintech.ru>
/// \version 1.0.0.0
/// \date 01.01.2019

#include "selinux_config_sysconfig_selinux_test.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>


namespace fintech {
namespace security_self_tests {

void SelinuxConfigSysconfigSelinuxTest::ParseConfigFile() {
  auto status = false;
  if (IsFileExist()) {
    CalcFileSize();
    if (IsValid("SELINUX") && IsValid("SELINUXTYPE"))
      status = true;
  }
  ValidateConfig(status);
}

void SelinuxConfigSysconfigSelinuxTest::Print() const {
  std::cout << "Configure file " << GetPath() << " is";
  if (!IsConfigValid())
    std::cout << " not ";
  std::cout << "valid" << std::endl;
}

bool SelinuxConfigSysconfigSelinuxTest::IsValid(const std::string &parameter) {
  auto status = false;
  std::ifstream fd;
  fd.open(GetPath());
  if (fd.is_open()) {
    std::string line{};
    std::string result{};
    std::map<std::string, std::vector<std::string>> config_map {
      {"SELINUX", {"enforcing", "permission", "disabled"}},
      {"SELINUXTYPE", {"targeted", "minimum", "mls"}},
    };

    while (std::getline(fd, line)) {
      auto res = line.find(parameter);
      if (res != std::string::npos) {
        //result = line.substr(0, parameter.size() + 1);
        if (line.find("#") == std::string::npos &&
          line.find("=") != std::string::npos) {
          
          std::cout << "here" << std::endl;
          result = line.substr((line.find("=")) + 1);
          std::cout << "result " << result << std::endl;
          auto vc = config_map[parameter];
          status = (std::find(std::begin(vc), std::end(vc), result) != std::end(vc));
        }
      }
    }
    fd.close();
  } else {
    std::cout << "Coldn't open the file " << GetPath() << std::endl;
  }
  std::cout << "status is " << ((status) ? "true" : "false") << std::endl;
  return status;
}
}
}
