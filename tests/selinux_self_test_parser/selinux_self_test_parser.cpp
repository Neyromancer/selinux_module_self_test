/// \file selinux_self_test_parser.cpp
/// \brief
/// \author Dmitry Kormulev <kormulev@fintech.ru>
/// \version 1.0.0.0
/// \date 22.01.2019

#include "selinux_self_test_parser.h"

#include <fstream>
#include <iostream>

namespace fintech {
namespace security_self_tests {
void SelinuxSelfTestParser::ParseConfigFile() {
  if (!IsFileExist())
    throw std::invalid_argument("invalid config file path");
  
  std::ifstream fd (GetPath());
  if (fd.is_open()) {
    std::string line{};
    auto is_file = false;
    auto is_dir = false;
    while (std::getline(fd, line)) {
      if (line == "[dir]") {
        is_dir = true;
        is_file = false;
      }

      if (!is_dir && is_file && !line.empty())
        SetLstFile(line);

      if (!is_file && is_dir && !line.empty())
        SetLstDir(line);

      if (line == "[file]")
        is_file = true;
    }
  }
}

void SelinuxSelfTestParser::SetLstFile(const std::string &fpath) {
//  if (IsValidFile(fpath))
    lst_file_.push_back(fpath);
}

void SelinuxSelfTestParser::SetLstFile(std::string &&fpath) {
//  if (IsValidFile(fpath))
    lst_file_.push_back(fpath);
}

void SelinuxSelfTestParser::SetLstDir(const std::string &dpath) {
//  if (IsValidDir(dpath))
    lst_dir_.push_back(dpath);
}

void SelinuxSelfTestParser::SetLstDir(std::string &&dpath) {
//  if (IsValidDir(dpath))
    lst_dir_.push_back(dpath);
}

}
}
