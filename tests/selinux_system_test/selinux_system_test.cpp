/// \file selinux_system_test.cpp
/// \brief
/// \author Dmitry Kormulev <kormulev@fintech.ru>
/// \version 1.0.0.2
/// \date 21.01.2019

#include "selinux_system_test.h"

extern "C" {
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
}

#include <exception>
#include <cerrno>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>

namespace fintech {
namespace security_self_tests {

void SelinuxSystemTest::SetPath(const std::string &path) {
  std::cout << "path: " << path << std::endl; 
  struct stat sb{};
  if (lstat(path.c_str(), &sb) == -1) {
    std::cout << "lstat: " << std::strerror(errno) << std::endl;
    throw std::invalid_argument("wrong path");
  }

  if (S_IFDIR == (sb.st_mode & S_IFMT)) {
    is_dir_exist_ = true;
  }

  if (S_IFREG == (sb.st_mode & S_IFMT) || 
      S_ISREG(sb.st_mode & S_IFMT))
    is_file_exist_ = true; 

  if (S_IFLNK == (sb.st_mode & S_IFMT) ||
      S_ISLNK(sb.st_mode & S_IFMT))
    is_symlink_exist_ = true;

  if (!is_symlink_exist_) {
    path_ = path;
  } else {
    char *link_name = nullptr;
    auto buf_size = sb.st_size + 1;

    link_name = (char *)malloc(buf_size);
    if (!link_name)
      std::cout << "could not allocate enough space" << std::endl;

    auto link_size = 0;
    if ((link_size = readlink(path.c_str(), link_name, buf_size)) < 0) {
      free (link_name);
      throw std::invalid_argument("wrong argument");
    }

    if (link_size >= buf_size) {
      free (link_name);
      throw std::invalid_argument("symlink increased in size");   // change to a appropriate exception
    }

    
    link_name[buf_size] = '\0';
    path_ = std::move(std::string(link_name));
    free(link_name);
  }
}

void SelinuxSystemTest::SetPath(std::string &&path) {
  struct stat sb{};
  std::cout << "path: " << path << std::endl; 
  if (lstat(path.c_str(), &sb) == -1)
    throw std::invalid_argument("wrong path");

  if (S_IFDIR == (sb.st_mode & S_IFMT))
    is_dir_exist_ = true;

  if (S_IFREG == (sb.st_mode & S_IFMT) || 
      S_ISREG(sb.st_mode & S_IFMT))
    is_file_exist_ = true; 

  if (S_IFLNK == (sb.st_mode & S_IFMT) ||
      S_ISLNK(sb.st_mode & S_IFMT))
    is_symlink_exist_ = true;

  if (!is_symlink_exist_) {
    path_ = std::move(path);
  } else {
    char *link_name = nullptr;
    auto buf_size = sb.st_size + 1;

    link_name = (char *)malloc(buf_size);
    if (!link_name)
      std::cout << "could not allocate enough space" << std::endl;

    auto link_size = 0;
    if ((link_size = readlink(path.c_str(), link_name, buf_size)) < 0) {
      free (link_name);
      throw std::invalid_argument("wrong argument");
    }

    if (link_size >= buf_size) {
      free (link_name);
      throw std::invalid_argument("symlink increased in size");   // change to an appropriate exception
    }

    path_ = std::move(std::string(link_name));
    free(link_name);
  }
}
}  // namespace security_self_tests
}  // namespace fintech
