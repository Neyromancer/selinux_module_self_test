/// \file main.cpp
/// \brief
/// \author Dmitry Kormulev <kormulev@fintech.ru>
/// \version 1.0.0.0
/// \date 11.12.2018

#include <cstdlib>
#include <iostream>

#include "./selinux_self_test_engine/selinux_self_test_engine.h"

int main(void) {
  fintech::security_self_tests::SelinuxSelfTestEngine seself_test_engine;
  seself_test_engine.ProcessSelinuxSelfTest();

  return EXIT_SUCCESS;
}
