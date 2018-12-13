/// \file selinux_system_test.cpp
/// \brief
/// \author Dmitry Kormulev <kormulev@fintech.ru>
/// \version 1.0.0.0
/// \date 05.12.2018

#include "selinux_system_test.h"

extern "C" {
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
}

#include <cstdio>
#include <string>
#include <stdexcept>

namespace fintech {
namespace security_self_tests {

void SelinuxSystemTest::SetPath(const std::string &path) {
  struct stat sb;
  if (stat(path.c_str(), &sb) == -1)
    throw std::invalid_argument("wrong path");

  /*   this block think that passed file is not a reg file.
    if (S_IFREG != (sb.st_mode & S_IFMT)) {
    throw std::invalid_argument("wrong path");
  }*/

  path_ = path;

  is_file_exist_ = true; 
}

void SelinuxSystemTest::SetPath(std::string &&path) {
  struct stat sb;
  if (stat(path.c_str(), &sb) == -1)
    throw std::invalid_argument("wrong path");

  /*   this block think that passed file is not a reg file.
    if (S_IFREG != (sb.st_mode & S_IFMT)) {
    throw std::invalid_argument("wrong path");
  }*/

  path_ = path;

  is_file_exist_ = true; 
}
}  // namespace security_self_tests
}  // namespace fintech
