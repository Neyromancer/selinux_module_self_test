/// \file selinux_config_test.cpp
/// \brief
/// \author Dmitry Kormulev <kormulev@fintech.ru>
/// \version 1.0.0.0
/// \date 22.12.2018

#include "selinux_config_test.h"

extern "C" {
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
}

namespace fintech {
namespace security_self_tests {

//void SelinuxConfigTest::ParseConfigFile() {
//  if (IsFileExist()) {
//    CalcFileSize();
//  }
//}

void SelinuxConfigTest::CalcFileSize() {
  struct stat sb;
  if (stat(GetPath().c_str(), &sb) == -1)
    throw std::invalid_argument("Wrong path argument.");

  config_file_size_ = static_cast<uint64_t>(sb.st_size);  
}

}  // namespace securiy_self_tests
}  // namespace fintech
