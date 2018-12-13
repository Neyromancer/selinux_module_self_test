/// \file selinux_module_test.cpp
/// \brief
/// \author Dmitry Kormulev <kormulev@fintech.ru>
/// \version 1.0.0.2
/// \date 12.12.2018

#include "selinux_module_test.h"

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <vector>

namespace fintech {
namespace security_self_tests {

#define kKernelVersion "/proc/version"

static int StartOfVersionPosition(const std::string &);
static std::string GetParameterValue(const std::string &, const std::string &);
static std::string ToLowerCase(const std::string &);

void SelinuxModuleTest::ParseBootConfigFile() {
  std::string config_name = GetBootConfigFileName();
  std::cout << "config_name" << config_name << "|" << std::endl;
  SetPath(config_name);
  if (!IsFileExist())
    std::cout << "file " << config_name << "does not exist" << std::endl;
  
  auto is_secure_selinux = false;
  if (GetParameterValue(config_name, "CONFIG_SECURITY_SELINUX") == "y")
    is_secure_selinux = true;
  
  auto is_default_security = false;
  if (GetParameterValue(config_name, "CONFIG_DEFAULT_SECURITY") == "selinux")
    is_default_security = true;

  if (is_secure_selinux && is_default_security)
    is_selinux_module_exist_ = true;
}

std::string SelinuxModuleTest::GetBootConfigFileName() {
  std::string config_name = "/boot/config-";
  config_name += GetKernelVersion();
  return config_name;
}

std::string SelinuxModuleTest::GetKernelVersion() {
  std::string kernel_version {};
  std::ifstream fd;
  fd.open(kKernelVersion);
  if (fd.is_open()) {
    std::string line {};
    while (std::getline(fd, line)) {
      auto el2 = line.find_first_of("(");
      auto position_of_frst_decimal_in_version = StartOfVersionPosition(line);
      auto count = el2 - position_of_frst_decimal_in_version - 1;
      kernel_version = line.substr(position_of_frst_decimal_in_version, count);
    }
  }
  return kernel_version;
}

int StartOfVersionPosition(const std::string &line) {
  auto cnt = 0;
  for (const auto &el : line) {
    if (std::isdigit(el)) 
      return cnt;
    ++cnt;
  }     
}

std::string GetParameterValue(const std::string &fname, 
                              const std::string &line) {
  std::ifstream fd;
  fd.open(fname);
  std::vector<std::string> vc_storage;
  if (fd.is_open()) {
    std::string tmp;
    while (std::getline(fd, tmp))
      vc_storage.push_back(tmp);
    fd.close();
  } else {
    std::cout << "Can't open file " << fname << std::endl;
  }

  std::string result {};
  for (const auto &el : vc_storage) {
    auto res = el.find(line);
    if (res != std::string::npos) {
      result = el.substr(line.size());
      if (result.find("=") != std::string::npos) {
        auto tmp = result.substr(1, result.size() - 1);
        return ToLowerCase(tmp);
      }
    }
  }

  return "";
}

std::string ToLowerCase(const std::string &line) {
  std::string res {};
  for (const auto &el : line) {
    if (isalpha(el))
      res += std::tolower(el);
    else 
      res += el;
  }
  return res;
}
} // namespace security_self_tests
} // namespace fintech
