/// \file selinux_module_test.h
/// \brief Заголовочный файл класса проверки наличия модуля SELinux.
/// \author Dmitry Kormulev <kormulev@fintech.ru>
/// \version 1.0.0.1
/// \date 17.01.2019

#ifndef SECURITY_SELF_TEST_SECURITY_TESTS_SELINUX_TEST_SELINUX_MODULE_TEST_H_
#define SECURITY_SELF_TEST_SECURITY_TESTS_SELINUX_TEST_SELINUX_MODULE_TEST_H_

#include <string>

#include "../selinux_system_test/selinux_system_test.h"

/// \namespace fintech.
/// \brief Область видимости проектов АО "ФИНТЕХ".
namespace fintech {
/// \namespace security_self_tests.
/// \brief Область видимости системы самотестирования.
namespace security_self_tests {
/// \class SelinuxModuleTest
/// \class selinux_module_test.h
/// \brief Класс тестирования наличия модуля SELinux.
class SelinuxModuleTest: public SelinuxSystemTest {
 public:
  /// \brief Конструктор класса SelinuxModuleTest.
  SelinuxModuleTest() {}

  /// \brief Деструктор класса SelinuxModuleTest.
  ~SelinuxModuleTest() = default;

  /// \brief Парсит файл.
  void ParseBootConfigFile();

  /// \brief Возвращает результат проверки существования модуля SELinux.
  /// \return Состояние модуля SELinux.
  inline bool IsSelinuxModuleExist() const noexcept {
    return is_selinux_module_exist_;
  }

 private:
  /// \brief Возвращает весрию ядра.
  /// \return Версия ядра.
  std::string GetKernelVersion();
 
  /// \brief Возвращает имя файла настройки запуска.
  /// \return Имя файла настройки запуска.
  std::string GetBootConfigFileName();

  bool is_selinux_module_exist_{false};
};
}   // namespace security_self_test
}   // namespace fintech

#endif  // SECURITY_SELF_TEST_SECURITY_TESTS_SELINUX_TEST_SELINUX_MODULE_TEST_

