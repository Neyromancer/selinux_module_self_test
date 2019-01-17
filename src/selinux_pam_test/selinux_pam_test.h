/// \file selinux_pam_test.h
/// \brief Заголовочный файл класса SELinuxPamTest.
/// \author Dmitry Kormulev <kormulev@fintech.ru>
/// \version 1.0.0.0
/// \date 13.12.2018

#ifndef SECURITY_SELF_TEST_SECURITY_TESTS_SELINUX_TEST_SELINUX_PAM_TEST_H_
#define SECURITY_SELF_TEST_SECURITY_TESTS_SELINUX_TEST_SELINUX_PAM_TEST_H_

#include "../selinux_system_test/selinux_system_test.h"

/// \namespace fintech.
/// \brief Область видимости проектов АО "ФИНТЕХ".
namespace fintech {
/// \namespace security_self_tests.
/// \brief Область видимости системы самотестирования.
namespace security_self_tests {
/// \class SelinuxPamTest.
/// \class SelinuxPamTest selinux_pam_test.h.
/// \brief Класс проверки наличия записи о SELinux в PAM-модулях.
class SelinuxPamTest: public SelinuxSystemTest {
 public:
  /// \brief Конструктор класса SelinuxPamTest.
  SelinuxPamTest() {}

  /// \brief Деструктор класса SelinuxPamTest.
  ~SelinuxPamTest() = default;
 
  /// \brief Конструктор копирования класса SelinuxPamTest.
  /// \param[in] selinux_pam_test Объект класса SelinuxPamTest.
  SelinuxPamTest(const SelinuxPamTest &selinux_pam_test) = delete;

  /// \brief Конструктор перемещения класса SelinuxPamTest.
  /// \param[in] selinux_pam_test Объект класса SelinuxPamTest.
  SelinuxPamTest(SelinuxPamTest &&selinux_pam_test) = default;

  /// \brief Оператор присваивания копированием класса SelinuxPamTest.
  /// \param[in] selinux_pam_test Объект класса SelinuxPamTest.
  /// \return Объект класса SelinuxPamTest.
  SelinuxPamTest &operator=(const SelinuxPamTest &selinux_pam_test) = delete;

  /// \brief Оператор присваивания перемещением класса SelinuxPamTest.
  /// \param[in] selinux_pam_test Объект класса SelinuxPamTest.
  /// \return Объект класса SelinuxPamTest.
  SelinuxPamTest &operator=(SelinuxPamTest &selinx_pam_test) = default;

  /// \brief Возвращает результат проверки нахождения записи
  /// \brief о SELinux в PAM-модуле.
  /// \return Результат проверки нахождения записи о SELinux
  /// \return в PAM-модуле.
  inline bool IsPamCorrect() const noexcept {
    return is_pam_correct_;
  }

  /// \brief Парсит PAM-модули.
  void ParsePamModules();

 private:
  /// \brief Определяет сколько раз в файле 
  /// \brief встречается переданный параметр.
  /// \param[in] fname Имя файла.
  /// \param[in] parameter Параметр, который ищем в
  /// \param[in] файле.
  /// \return Количество появления параметра в файле.
  int CountParameterAppearance(const std::string &fname, 
                               const std::string &parameter);

  bool is_pam_correct_{false}; 
};
}  // namespace security_self_tests
}  // namespace fintech

#endif  //  SECURITY_SELF_TEST_SECURITY_TESTS_SELINUX_TEST_SELINUX_PAM_TEST_H_
