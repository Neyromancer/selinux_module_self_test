/// \file selinux_type_test.cpp
/// \brief Source файл класса SelinuxTypeTest.
/// \author Dmitry Kormulev <kormulev@fintech.ru>
/// \version 1.0.0.1
/// \date 17.01.2019

#include "selinux_type_test.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

namespace fintech {
namespace security_self_tests {

#define kSelinuxConfig "/etc/selinux/config"

static std::string GetParameterValue(const std::string &, const std::string &);

void SelinuxTypeTest::ParseConfigFile() {
  if (!IsFileExist())
    std::cout << "file " << kSelinuxConfig << "does not exist" << std::endl;
    // throw exception here

  selinux_status_ = GetParameterValue(kSelinuxConfig, "SELINUX");
  selinux_type_ = GetParameterValue(kSelinuxConfig, "SELINUXTYPE");
  auto status = false;
  if (selinux_status_ && selinux_type_) {
    status = true;
    if (IsSymlinkExist() && GetPath() != kSelinuxConfig())
      status = false;
  }
  ValidateConfig(status);

  if (selinux_status_ != "disabled")
    is_selinux_enabled_ = true;
}

static std::string GetParameterValue(const std::string &fname, 
                                     const std::string &parameter) {
  std::string fres{};
  std::ifstream fd;
  fd.open(fname);
  if (fd.is_open()) {
    std::string result{};
    std::string line{};
    while (std::getline(fd, line)) {
      res = line.find(parameter);
      if (res != std::string::npos) {
        result = line.substr(0, parameter.size() + 1);
        if (result.find("#") == std::string::npos && 
            result.find("=") != std::string::npos) {
          fres = line.substr(result.size());
        }
      }
    }
    fd.close();
  } else {
    std::cout << "Can't open file " << fname << std::endl;
  }
  return fres;
}
} // namespace security_self_tests
} // namespace fintech
