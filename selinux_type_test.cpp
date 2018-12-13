/// \file selinux_type_test.cpp
/// \brief
/// \author Dmitry Kormulev <kormulev@fintech.ru>
/// \version 1.0.0.0
/// \date 12.12.2018

#include "selinux_type_test.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

namespace fintech {
namespace security_self_tests {

#define kSelinuxConfig "/etc/selinux/config"

static std::string GetParameterValue(const std::string &, const std::string &);

void SelinuxTypeTest::ParseSelinuxConfig() {
  SetPath(kSelinuxConfig);
  if (!IsFileExist())
    std::cout << "file " << kSelinuxConfig << "does not exist" << std::endl;
    // throw exception here

  selinux_status_ = GetParameterValue(kSelinuxConfig, "SELINUX");
  selinux_type_ = GetParameterValue(kSelinuxConfig, "SELINUXTYPE"); 
}

static std::string GetParameterValue(const std::string &fname, 
                                     const std::string &parameter) {
  std::ifstream fd;
  fd.open(fname);
  if (fd.is_open()) {
    std::string result {};
    std::string line {};
    while (std::getline(fd, line)) {
      auto res = line.find(parameter);
      if (res != std::string::npos) {
        result = line.substr(0, parameter.size() + 1);
        if (result.find("#") == std::string::npos && 
            result.find("=") != std::string::npos) {
          auto tmp = line.substr(result.size());
          return tmp;
        }
      }
    }
    fd.close();
  } else {
    std::cout << "Can't open file " << fname << std::endl;
  }
  return "";
}
} // namespace security_self_tests
} // namespace fintech
