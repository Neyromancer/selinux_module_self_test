/// \file selinux_type_test.h
/// \brief Заголовочный файл класса SelinuxTypeTest.
/// \author Dmitry Kormulev <kormulev@fintech.ru>
/// \version 1.0.0.1
/// \date 17.01.2019

#ifndef SECURITY_SELF_TEST_SECURITY_TESTS_SELINUX_TEST_SELINUX_TYPE_TEST_H_
#define SECURITY_SELF_TEST_SECURITY_TESTS_SELINUX_TEST_SELINUX_TYPE_TEST_H_

#include <string>

#include "../selinux_system_test/selinux_system_test.h"

/// \namespace fintech.
/// \brief Область видимости проетков АО "ФИНТЕХ".
namespace fintech {
/// \namespace security_self_tests.
/// \brief Область видимости системы самотестирования.
namespace security_self_tests {
/// \class SelinuxTypeTest selinux_type_test.h.
/// \brief Класс проверки режима, в котором установлен SELinux.
class SelinuxTypeTest: public SelinuxSystemTest {
 public:
  /// \brief Конструктор класса SelinuxTypeTest.
  SelinuxTypeTest() {}
  
  /// \brief Деструктор класса SelinuxTypeTest.
  ~SelinuxTypeTest() = default;

  /// \brief Конструктор копирования класса SelinuxTypeTest.
  /// \param[in] selinux_type_test Объект касса SelinuxTypeTest.
  SelinuxTypeTest(const SelinuxTypeTest &selinux_type_test) = delete;

  /// \brief Конструктор перемешения класса SelinuxTypeTest.
  /// \param[in] selinux_type_test Объект класса SelinuxTypeTest.
  SelinuxTypeTest(SelinuxTypeTest &&selinux_type_test) = default;

  /// \brief Оператор присваивания копированием класса SelinuxTypeTest.
  /// \param[in] selinux_type_test Объект класса SelinuxTypeTest.
  /// \return Объект класса SelinuxTypeTest.
  SelinuxTypeTest &operator=(const SelinuxTypeTest &selinux_type_test) = delete;

  /// \brief Оператор присваивания перемещением класса SelinuxTypeTest.
  /// \param[in] selinux_type_test Объект класса SelinuxTypeTest.
  /// \return Объект класса SelinuxTypeTest.
  SelinuxTypeTest &operator=(SelinuxTypeTest &&selinux_type_test) = default;

  /// \brief Возвращает текущий тип SELinux защиты.
  /// \return Текущий тип SELinux защиты.
  inline std::string GetSelinuxType() const noexcept {
    return selinux_type_;
  }

  /// \brief Возвращает текущий статус SELinux.
  /// \return Текущий статус SELinux.
  inline std::string GetSelinuxStatus() const noexcept {
    return selinux_status_;
  }

  /// \brief Парсит файл.
  void ParseSelinuxConfig();

  private:
    std::string selinux_status_{};
    std::string selinux_type_{}; 
};
}  // namespace security_self_tests
}  // namespace fintech

#endif  // SECURITY_SELF_TEST_SECURITY_TESTS_SELINUX_TEST_SELINUX_TYPE_TEST_H_
