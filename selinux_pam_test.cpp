/// \file selinux_pam_test.cpp
/// \brief
/// \author Dmitry Kormulev <kormulev@fintech.ru>
/// \version 1.0.0.0
/// \date 13.12.2018

#include "selinux_pam_test.h"

#include <fstream>
#include <iostream>
#include <vector>
#include <string>


namespace fintech {
namespace security_self_tests {

//static int CountParameterAppearance(const std::string &, const std::string &);

void SelinuxPamTest::ParsePamModules() {
  const std::string path = "/etc/pam.d/";
  const std::vector<std::string> pam_vc = { "gdm-pin", "gdm-password", 
                                            "gdm-ovirtcred", "gdm-fingerprint", 
                                            "remote", "gdm-autologin", 
                                            "gdm-smartcard", "login", "sshd" };

  is_pam_correct_ = true;
  for (const auto &el : pam_vc) {
    auto file = path + el;
    if (CountParameterAppearance(file, "pam_selinux.so") != 2) {
      is_pam_correct_ = false;
      break;
    }
  }
}

int SelinuxPamTest::CountParameterAppearance(const std::string &fname, 
                             const std::string &parameter) {
  int count {0};
  SetPath(fname);
  if (!IsFileExist()) {
    std::cout << "file " << fname << "does not exist" << std::endl;
  } else {
    std::ifstream fd;
    fd.open(fname);
    if (fd.is_open()) {
      std::string line;
      while (std::getline(fd, line)) {
        auto sepam = line.find(parameter);
        auto shebang_symbol = line.find("#");
        if (sepam != std::string::npos && 
            shebang_symbol == std::string::npos) {
            ++count;
        }
      }
    }
  }
  return count;
}
}
}
