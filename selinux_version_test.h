/// \file selinux_version_test.h
/// \brief
/// \author Dmitry Kormulev <kormulev@fintech.ru>
/// \version 1.0.0.1
/// \date 21.12.2018

#ifndef SECURITY_SELF_TEST_SECURITY_TESTS_SELINUX_TEST_SELINUX_VERSION_TEST_H_
#define SECURITY_SELF_TEST_SECURITY_TESTS_SELINUX_TEST_SELINUX_VERSION_TEST_H_

#include "selinux_system_test.h"

/// \brief Область видимости проектов АО "ФИНТЕХ".
namespace fintech {
/// \brief Область видимости системы самотестирования.
namespace security_self_tests {
/// \class SelinuxVersionTest selinux_type_test.h
class SelinuxVersionTest: public SelinuxSystemTest {
 public:
  /// \brief Конструктор класса SelinuxVersionTest.
  SelinuxVersionTest() {}

  /// \brief Деструктор класса SelinuxVersionTest.
  ~SelinuxVersionTest() = default;

  /// \brief Конструктор копирования класса SelinuxVersionTest.
  /// \param[in] selinux_version_test Объект класса SelinuxVersionTest.
  SelinuxVersionTest(const SelinuxVersionTest &selinux_version_test) = delete;

  /// \brief Конструктор перемещения класса SelinuxVersionTest.
  /// \param[in] selinux_version_test Объект класса SelinuxVersionTest.
  SelinuxVersionTest(SelinuxVersionTest &&selinux_version_test) = default;

  /// \brief Оператор присваивания копирования класса SelinuxVersionTest.
  /// \param[in] selinux_version_test Объект класса SelinuxVersionTest.
  /// \return Объект класса SelinuxVersionTest.
  SelinuxVersionTest &operator=(const SelinuxVersionTest &selinux_version_test) = delete;

  /// \brief Оператор присваивания перемещением класса SelinuxVersionTest.
  /// \param[in] selinux_version_test Объект класса SelinuxVersionTest.
  /// \return Объект класса SelinuxVersionTest.
  SelinuxVersionTest &operator=(SelinuxVersionTest &&selinux_version_test) = default;

  /// \brief Возвращает версию ядра SELinux.
  /// \return Версия ядра SELinux.
  inline int GetSelinuxVersion() const noexcept {
    return selinux_version_;
  }

  /// \brief Определяет и устанавливает версию ядра SELinux.
  void SetSelinuxVersion();

  /// \brief Выводит в консоль информацию по версии ядра SELinux.
  void PrintSelinuxVersion();

 private:
  /// \brief Парсит директорию.
  /// \param[in] path Путь до директории.
  /// \return Возвращает файл имеющий формат ядра SELinux.
  std::string ParseSelinuxPolicyDir(const std::string &path);
  std::string ParseSelinuxPolicyDir(std::string &&path);

  int selinux_version_{};
  
};
}  // namespace security_self_tests
}  // namespace fintech

#endif  // SECURITY_SELF_TEST_SECURITY_TESTS_SELINUX_TEST_SELINUX_VERSION_TEST_H_
