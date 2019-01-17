/// \file selinux_config_sysconfig_selinux_test.h
/// \brief Заголовочный файл класса тестирования конфигурационного файла
/// \brief selinux.
/// \author Dmitry Kormulev <kormulev@fintech.ru>
/// \version 1.0.0.0
/// \date 22.12.2018

#ifndef SECURITY_SELF_TEST_SECURITY_TESTS_SELINUX_TEST_SELINUX_CONFIG_SYSCONFIG_SELINUX_TEST_H_
#define SECURITY_SELF_TEST_SECURITY_TESTS_SELINUX_TEST_SELINUX_CONFIG_SYSCONFIG_SELINUX_TEST_H_

#include <string>

#include "../selinux_config_test/selinux_config_test.h"

/// \namespace fintech.
/// \brief Область видимости проектов АО "ФИНТЕХ".
namespace fintech {
/// \namespace security_self_tests.
/// \brief Область видимости системы самотестирования.
namespace security_self_tests {

/// \class SelinuxConfigSysconfigSelinuxTest.
/// \class selinux_config_sysconfig_selinux_test.h
/// \brief Класс тестирования конфигурационного файла selinux модуля SELinux.
class SelinuxConfigSysconfigSelinuxTest: public SelinuxConfigTest {
 public:
  /// \brief Конструктор класса SelinuxConfigSysconfigSelinuxTest.
  SelinuxConfigSysconfigSelinuxTest() {}

  /// \brief Деструктор класса SelinuxConfigSysconfigSelinuxTest.
  ~SelinuxConfigSysconfigSelinuxTest() = default;

  /// \brief Конструктор копирования класса SelinuxConfigSysconfigSelinuxTest.
  /// \param[in] selinux_config_sysconfig_selinux_test Объект класса
  /// \param[in] SelinuxConfigSysconfigSelinuxTest.
  SelinuxConfigSysconfigSelinuxTest(const SelinuxConfigSysconfigSelinuxTest
                                    &selinux_config_sysconfig_test) = delete;

  /// \brief Конструктор перемещения класса SelinuxConfigSysconfigSelinuxTest.
  /// \prarm[in] selinux_config_sysconfig_selinux_test Объект класса
  /// \param[in] SelinuxConfigSysconfigSelinuxTest.
  SelinuxConfigSysconfigSelinuxTest(SelinuxConfigSysconfigSelinuxTest
                                    &&selinux_config_sysconfig_test) = default;

  /// \brief Оператор присваивания копированием класса
  /// \brief SelinuxConfigSysconfigSelinuxTest.
  /// \param[in] selinux_config_sysconfig_selinux_test Объект класса
  /// \param[in] SelinuxConfigSysconfigSelinuxTest.
  /// \return Объект класса SelinuxConfigSysconfigSelinuxTest.
  SelinuxConfigSysconfigSelinuxTest &operator=(
  const SelinuxConfigSysconfigSelinuxTest &selinux_config_sysconfig_selinux_test
  ) = delete;

  /// \brief Оператор присваивания перемещением класса
  /// \brief SelinuxConfigSysconfigSelinuxTest.
  /// \param[in] selinux_config_sysconfig_selinux_test Объект класса
  /// \param[in] SelinuxConfigSysconfigSelinuxTest.
  SelinuxConfigSysconfigSelinuxTest &operator=(
  SelinuxConfigSysconfigSelinuxTest &&selinux_config_sysconfig_selinux_test
  ) = default;

  /// \brief Парсит конфигурационный файл.
  void ParseConfigFile() override;

  /// \brief Выводит сообщение по ходу работы программы.
  void Print() const;

 private:
  bool IsValid(const std::string &);

};
}  // namespace security_self_tets
}   // namespace fintech
#endif  // SECURITY_SELF_TEST_SECURITY_TESTS_SELINUX_TEST_SELINUX_CONFIG_SYSCONFIG_SELINUX_TEST_H_

