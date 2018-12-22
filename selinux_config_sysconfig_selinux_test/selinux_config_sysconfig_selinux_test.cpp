/// \file selinux_config_sysconfig_selinux_test.cpp
/// \brief
/// \author Dmitry Kormulev <kormulev@fintech.ru>
/// \version 1.0.0.0
/// \date 22.12.2018

#include "selinux_config_sysconfig_selinux_test.h"

#include <fstream>
#include <map>
#include <vector>

namespace fintech {
namespace security_self_test {

static bool IsValid(std::string &&);

void SelinuxConfigSysconfigSelinuxTest::ParseConfigFile() {
  auto status = false;
  SelinuxConfigTest::ParseConfigFile();
  if (IsFileSizeNoneNull()) {
    if (IsValid("SELINUX") && IsValid("SELINUXTYPE"))
      status = true;
  }
  ValidateConfig(status);
}

void Print() const {
  std::cout << "Configure file " << GetPath() << " is";
  if (!IsConfigValid())
    std::cout << " not  ";
  std::cout << "valid" << std::endl;
}

static bool IsValid(std::string &&parameter) {
  auto status = false;
  std::ifstream fd;
  fd.open(GetPath());
  if (fd.is_open()) {
    std::string line{};
    std::string result{};
    const std::map<std::string, std::vector<std::string>> config_map {
      {"SELINUX", {"enforcing", "permission", "disabled"}},
      {"SELINUXTYPE", {"targeted", "minimum", "mls"}},
    };

    while (std::getline(fd, line)) {
      auto res = line.find(parameter);
      if (res != std::string::npos) {
        result = line.substr(0, parameter.size() + 1);
        if (result.find("#") == std::string::npos &&
          result.find("=") != std::string::npos) {
          auto vc = config_map[parameter];
          status = (std::find(std::begin(vc), std::end(vc), parameter) ==
                    std::end(vc));
        }
      }
    }
    fd.close();
  } else {
    std::cout << "Coldn't open the file " << GetPath() << std::endl;
  }
  return status;
}
}
}
