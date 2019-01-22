/// \file selinux_self_test_engine.h
/// \brief Файл запуска и обработки вызовов тестов модуля SELinux.
/// \author Dmitry Kormulev <kormulev@fintech.ru>
/// \version 1.0.0.0
/// \date 22.01.2019

#ifndef SELINUX_ENGINE_H_
#define SELINUX_ENGINE_H_

#include <memory>
#include <string>
#include <vector>

#include "../selinux_config_test/selinux_config_test.h"
#include "../selinux_module_test/selinux_module_test.h"
#include "../selinux_pam_test/selinux_pam_test.h"
#include "../selinux_self_test_parser/selinux_self_test_parser.h"
#include "../selinux_type_test/selinux_type_test.h"
#include "../selinux_version_test/selinux_version_test.h"

/// \namespace fintech
/// \brief Область видимости проектов АО "ФИНТЕХ".
namespace fintech {
/// \namespace security_self_tests.
/// \brief Область видимости системы самотестирования.
namespace security_self_tests {
/// \SelinuxSelfTestEngine selinux_self_test_engine.h
/// \brief Класс обработки SELinux тестов.
class SelinuxSelfTestEngine {
 public:
  /// \brief Конструктор класса SelinuxSelfTestEngine.
  SelinuxSelfTestEngine();

  /// \brief Деструктор класса SelinuxSelfTestEngine.
  ~SelinuxSelfTestEngine() = default;

  /// \brief Консктруктор копирования класса SelinuxSelfTestEngine.
  /// \param[in] separam Объект класса SelinuxSelfTestEngine.
  SelinuxSelfTestEngine(const SelinuxSelfTestEngine &separam) = delete;

  /// \brief Конструктор перемещения класса SelinuxSelfTestEngine.
  /// \param[in] separam Объект класса SelinuxSelfTestEngine.
  SelinuxSelfTestEngine(SelinuxSelfTestEngine &&separam) = default;

  /// \brief Оператор присваивания копированием класса SelinuxSelfTestEngine.
  /// \param[in] separam Объект класса SelinuxSelfTestEngine.
  /// \return Объект класса SelinuxSelfTestEngine.
  SelinuxSelfTestEngine &operator=(const SelinuxSelfTestEngine &separam) = delete;

  /// \brief Оператор присваивания перемещением класса SelinuxSelfTestEngine.
  /// \param[in] separam Объект класса SelinuxTestEngine.
  /// \return Объект класса SelinuxSelfTestEngine.
  SelinuxSelfTestEngine &operator=(SelinuxSelfTestEngine &&separam) = default;

  /// \brief Вызов и обработка тестов тестирования модуля SELinux.
  void ProcessSelinuxSelfTests();

 private:
  std::unique_ptr<SelinuxConfigTest> selinux_config_test_{};
  SelinuxModuleTest selinux_module_test_{;
  SelinuxPamTest selinux_pam_test_{};
  SelinuxTypeTest selinux_type_test_{};
  SelinuxVersionTest selinux_version_test_{};
  //SelinuxSelfTestParser selinux_self_test_parser_{};
};
}   // namespace security_self_test
}   // namespace fintech

#endif  // SELINUX_ENGINE_H_

