/// \file selinux_type_test.h
/// \brief Заголовочный файл класса SelinuxTypeTest.
/// \author Dmitry Kormulev <kormulev@fintech.ru>
/// \version 1.0.0.2
/// \date 22.01.2019

#ifndef SELINUX_TYPE_TEST_SELINUX_TYPE_TEST_H_
#define SELINUX_TYPE_TEST_SELINUX_TYPE_TEST_H_

#include <string>

#include "../selinux_config_test/selinux_config_test.h"
//#include "../selinux_system_test/selinux_system_test.h"

/// \namespace fintech.
/// \brief Область видимости проетков АО "ФИНТЕХ".
namespace fintech {
/// \namespace security_self_tests.
/// \brief Область видимости системы самотестирования.
namespace security_self_tests {
/// \class SelinuxTypeTest selinux_type_test.h.
/// \brief Класс проверки режима, в котором установлен SELinux.
class SelinuxTypeTest: public SelinuxConfigTest {
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
  void ParseConfigFile() /*override*/;

  /// \brief Возвращает состояние модуля SELinux.
  /// \return Булево состояние SELinux.
  bool IsSelinuxEnabled() const noexcept {
    return is_selinux_enabled_;
  }

  private:
    std::string selinux_status_{};
    std::string selinux_type_{};
    bool is_selinux_enabled_{false};
};
}  // namespace security_self_tests
}  // namespace fintech

#endif  // SELINUX_TYPE_TEST_SELINUX_TYPE_TEST_H_
