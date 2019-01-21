/// \file selinux_system_test.h
/// \brief
/// \author Dmitry Kormulev <kormulev@fintech.ru>
/// \version 1.0.0.2
/// \date 21.01.2019

#ifndef SECURITY_SELF_TEST_SECURITY_TESTS_SELINUX_TEST_SELINUX_SYSTEM_TEST_H_
#define SECURITY_SELF_TEST_SECURITY_TESTS_SELINUX_TEST_SELINUX_SYSTEM_TEST_H_

#include <string>

/// \namespace fintech.
/// \brief Область видимости проектов АО "ФИНТЕХ".
namespace fintech {
/// \namespace security_self_tests.
/// \brief Область видимости системы самотестирования.
namespace security_self_tests {
/// \class SelinuxSystemTest selinux_system_test.h
/// \brief Абстрактный класс парсера файлов.
class SelinuxSystemTest {
 public:
  /// \brief Конструктор класса SelinuxSystemTest.
  SelinuxSystemTest() {}

  /// \brief Деструктор класса SelinuxSystemTest.
  virtual ~SelinuxSystemTest() = default;

  /// \brief Конструктор копирования класса SelinuxSystemTest.
  /// \param[in] selinux_system_test Объект класса SelinuxSystemTest.
  SelinuxSystemTest(const SelinuxSystemTest &selinux_system_test) = delete;

  /// \brief Конструктор перемещения класса SelinuxSystemTest.
  /// \param[in] selinux_system_test Объект класса SelinuxSystemTest.
  SelinuxSystemTest(SelinuxSystemTest &&selinux_system_test) = default;

  /// \brief Оператор присваивания копированием класса SelinuxSystemTest.
  /// \param[in] selinux_system_test Объект класса SelinuxSystemTest.
  /// \return Объект класса SelinuxSystemTest.
  SelinuxSystemTest &operator=(const SelinuxSystemTest &selinux_system_test) = delete;

  /// \brief Оператор присваивания перемещением класса SelinuxSystemTest.
  /// \param[in] selinux_system_test Объект класса SelinuxSystemTest.
  /// \return Объект класса SelinuxSystemTest.
  SelinuxSystemTest &operator=(SelinuxSystemTest &&selinux_system_test) = default;

  /// \brief Устанавливает путь до файла.
  /// \param[in] path Путь до файла.
  void SetPath(const std::string &path);

  /// \brief Устанавливает путь до файла.
  /// \param[in] path Путь до файла.
  void SetPath(std::string &&path);

  /// \brief Возвращает путь до файла.
  /// \return Путь до файла.
  inline std::string GetPath() const noexcept { 
      return path_;
  }

  /// \brief Возвращает статус пути.
  /// \return Статус пути.
  inline bool IsFileExist() const noexcept { 
    return is_file_exist_; 
  }

  /// \brief Возвращает статус пути.
  /// \return Статус пути.
  inline bool IsDirExist() const noexcept { 
    return is_dir_exist_; 
  }

 private:
  std::string path_{};
  bool is_file_exist_{false};
  bool is_dir_exist_{false};
  bool is_symlink_exist_{false};
 
};
}   // namespace security_self_tests
}   // namespace fintech

#endif  // SECURITY_SELF_TEST_SECURITY_TESTS_SELINUX_TEST_SELINUX_SYSTEM_TEST_H_
