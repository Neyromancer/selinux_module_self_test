/// \file selinux_system_test.cpp
/// \brief
/// \author Dmitry Kormulev <kormulev@fintech.ru>
/// \version 1.0.0.1
/// \date 21.12.2018

#include "selinux_system_test.h"

extern "C" {
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
}

#include <cstdio>
#include <iostream>
#include <string>
#include <stdexcept>

namespace fintech {
namespace security_self_tests {

void SelinuxSystemTest::SetPath(const std::string &path) {
  struct stat sb;
  if (stat(path.c_str(), &sb) == -1)
    throw std::invalid_argument("wrong path");

  if (S_IFDIR == (sb.st_mode & S_IFMT)) {
    is_dir_exist_ = true;
  }

  if (!is_dir_exist_)
    is_file_exist_ = true; 

  path_ = path;
}

void SelinuxSystemTest::SetPath(std::string &&path) {
  struct stat sb;
  if (stat(path.c_str(), &sb) == -1)
    throw std::invalid_argument("wrong path");

  if (S_IFDIR == (sb.st_mode & S_IFMT)) {
    is_dir_exist_ = true;
  }

  if (!is_dir_exist_)
    is_file_exist_ = true; 

  path_ = path;
}
}  // namespace security_self_tests
}  // namespace fintech
