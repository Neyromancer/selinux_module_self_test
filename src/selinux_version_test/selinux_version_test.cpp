/// \file selinux_version_test.cpp
/// \brief Source файл класса SelinuxVersionTest.
/// \author Dmitry Kormulev <kormulev@fintech.ru>
/// \version 1.0.0.1
/// \date 21.12.2018

#include "selinux_version_test.h"

extern "C" {
#include <dirent.h>
}

#include <iostream>
#include <regex>

namespace fintech {
namespace security_self_tests {

#define kSelinuxPolicyVersionPath "/etc/selinux/targeted/policy"
// /etc/selinux/targeted/policy/policy.31

static bool IsSelinuxPolicyKernel(std::string &&fname);

void SelinuxVersionTest::SetSelinuxVersion() {
  std::string selinux_kernel = ParseSelinuxPolicyDir(kSelinuxPolicyVersionPath);
  selinux_version_ =
  std::stoi(selinux_kernel.substr(std::string("policy.").size()));
}

void SelinuxVersionTest::PrintSelinuxVersion() {
  std::cout << "selinux version " << selinux_version_ << std::endl;
}

std::string SelinuxVersionTest::ParseSelinuxPolicyDir(const std::string 
                                                      &selinux_policy_path) {
  std::string selinux_kernel{};
  SetPath(kSelinuxPolicyVersionPath);
  if (IsDirExist()) {
    DIR *dir_descriptor = opendir(kSelinuxPolicyVersionPath);
    if (!dir_descriptor) {
      std::cout << "Couldn't open dir " << kSelinuxPolicyVersionPath 
                << std::endl;
      // use appropriate throw here
    }
    struct dirent *dir_contents{};
    while (dir_contents = readdir(dir_descriptor)) {
      if (IsSelinuxPolicyKernel(std::string(dir_contents->d_name)))
        selinux_kernel = std::string(dir_contents->d_name);
    }
    closedir(dir_descriptor);
  } else {
    std::cout << "Directory " << kSelinuxPolicyVersionPath << " does not exist"
              << std::endl;
  }
  return selinux_kernel;
}

std::string SelinuxVersionTest::ParseSelinuxPolicyDir(std::string 
                                                      &&selinux_policy_path) {
  std::string selinux_kernel{};
  SetPath(kSelinuxPolicyVersionPath);
  if (IsDirExist()) {
    DIR *dir_descriptor = opendir(kSelinuxPolicyVersionPath);
    if (!dir_descriptor) {
      std::cout << "Couldn't open dir " << kSelinuxPolicyVersionPath 
                << std::endl;
      // use appropriate throw here
    }
    struct dirent *dir_contents{};
    while (dir_contents = readdir(dir_descriptor)) {
      if (IsSelinuxPolicyKernel(std::string(dir_contents->d_name)))
        selinux_kernel = std::string(dir_contents->d_name);
    }
    closedir(dir_descriptor);
  } else {
    std::cout << "Directory " << kSelinuxPolicyVersionPath << " does not exist"
              << std::endl;
  }
  return selinux_kernel;
}

static bool IsSelinuxPolicyKernel(std::string &&fname) {
  auto res = false;
  std::regex reg_expr ("\\b(policy.)\\d");
  if (std::regex_search(fname, reg_expr))
    res = true;
  return res;
}
}
}
