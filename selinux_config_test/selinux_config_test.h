/// \file selinux_config_test.h
/// \brief
/// \author Dmitry Kormulev <kormulev@fintech.ru>
/// \version 1.0.0.0
/// \date 22.12.2018

#ifndef SECURITY_SELF_TEST_SECURITY_TESTS_SELINUX_TEST_SELINUX_CONFIG_TEST_H_
#define SECURITY_SELF_TEST_SECURITY_TESTS_SELINUX_TEST_SELINUX_CONFIG_TEST_H_

#include <cstdint>

#include "../selinux_system_test/selinux_system_test.h"

/// \namespace fintech.
/// \brief Область видимости проектов АО "ФИНТЕХ".
namespace fintech {
/// \namespace security_self_tests.
/// \brief Область видимости системы самотестирования.
namespace security_self_tests {

/// \class SelinuxConfigTest selinux_config_test.h
/// \brief Абстрактный класс тестирования конфигурационных файлов модуля SELinux.
class SelinuxConfigTest: public SelinuxSystemTest {
 public:
  /// \brief Конструктор класса SelinuxConfigTest.
  SelinuxConfigTest() {}

  /// \brief Деструктор класса SelinuxConfigTest.
  virtual ~SelinuxConfigTest() = default;

  /// \brief Конструктор копирования класса SelinuxConfigTest.
  /// \param[in] selinux_config_test Объект класса SelinuxConfigTest.
  SelinuxConfigTest(const SelinuxConfigTest &selinux_config_test) = delete;

  /// \brief Конструктор перемещения класса SelinuxConfigTest.
  /// \param[in] selinux_config_test Объект класса SelinuxConfigTest.
  SelinuxConfigTest(SelinuxConfigTest &&selinux_config_test) = default;

  /// \brief Оператор присваивания копированием класса SelinuxConfigTest.
  /// \param[in] selinux_config_test Объект класса SelinuxConfigTest.
  /// \return Объект класса SelinuxConfigTest.
  SelinuxConfigTest &operator=(const SelinuxConfigTest &selinux_config_test) = delete;

  /// \brief Оператор присваивания перемещением класса SelinuxConfigTest.
  /// \param[in] selinux_config_test Объект класса SelinuxConfigTest.
  /// \return Объект класса SelinuxConfigTest.
  SelinuxConfigTest &operator=(SelinuxConfigTest &&selinux_config_test) = default;

  /// \brief Парсит конфигурационный файл.
  virtual void ParseConfigFile() = 0;

  /// \brief Возвращает размер конфигурационного файла.
  /// \return Размер конфигурационного файла.
  inline uint64_t GetConfigFileSize() const noexcept {
    return config_file_size_;
  }

  /// \brief Устанавливает валидность конфигурационного файла.
  inline void ValidateConfig(bool status) const noexcept {
    is_config_valid = status;
  }

  /// \brief 
  inline bool IsConfigValid() const noexcept {
    return is_config_valid_;
  }

  /// \brief Возвращает статус размера файла.
  /// \return Статус размера файла.
  inline bool IsFileSizeNoneNull() const noexcept {
    return config_file_size_ == 0;
  }

 private:
  /// \brief Определяет размер файла.
  void CalcFileSize();

  uint64_t config_file_size_{};
  bool is_config_valid_{false};

};
}   // namespace security_self_tests
}   // namespace fintech

#endif  // SECURITY_SELF_TEST_SECURITY_TESTS_SELINUX_TEST_SELINUX_CONFIG_TEST_H_

