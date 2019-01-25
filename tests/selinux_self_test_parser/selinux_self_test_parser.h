/// \file selinux_self_test_parser.h
/// \brief Заголовок класса чиатющего глобальный конфигурационный файл.
/// \author Dmitry Kormulev <kormulev@fintech.ru>
/// \version 1.0.0.0
/// \date 22.01.2019

#ifndef SELINUX_SELF_TEST_PARSER_SELINUX_SELF_TEST_PARSER_H_
#define SELINUX_SELF_TEST_PARSER_SELINUX_SELF_TEST_PARSER_H_

#include <vector>

#include "../selinux_config_test/selinux_config_test.h"

/// \namespace fintech.
/// \brief Область видимости проектов АО "ФИНТЕХ".
namespace fintech {
/// \brief Область видимости системы самотестирования.
/// \namespace security_self_tests.
namespace security_self_tests {
/// \class SelinuxSelfTestParser selinux_self_test_parser.h.
/// \brief Класс чтения конфигурационного файла приложения самотестирования.
class SelinuxSelfTestParser: public SelinuxConfigTest {
 public:
  /// \brief Конструктор класса SelinuxSelfTestParser.
  SelinuxSelfTestParser() {}
  
  /// \brief Деструктор класса SelinuxSelfTestParser.
  ~SelinuxSelfTestParser() = default;

  /// \brief Конструктор копирования класса SelinuxSelfTestParser.
  /// \param[in] separam Объект класса SelinuxSelfTestParser.
  SelinuxSelfTestParser(const SelinuxSelfTestParser &separam) = delete;

  /// \brief Конструктор перемещения класса SelinuxSelfTestParser.
  /// \param[in] separam Объект класса SelinuxSelfTestParser.
  SelinuxSelfTestParser(SelinuxSelfTestParser &&separam) = default;

  /// \brief Оператор присваивания копированием класса SelinuxSelfTestParser.
  /// \param[in] separam Объект класса SelinuxSelfTestParser.
  SelinuxSelfTestParser &operator=(const SelinuxSelfTestParser &separam) = delete;

  /// \brief Оператор присваивания перемещением класса SelinuxSelfTestParser.
  /// \param[in] separam Объект класса SelinuxSelfTestParser.
  SelinuxSelfTestParser &operator=(SelinuxSelfTestParser &&separam) = default;

  /// \brief Парсит конфигурационный файл.
  void ParseConfigFile() /*override*/;

  /// \brief Дополняет список файлов.
  /// \param[in] fpath Путь до файла.
  void SetLstFile(const std::string &fpath);
  void SetLstFile(std::string &&fpath);

  /// \brief Возвращает список файлов.
  /// \return Путь до файла.
  std::vector<std::string> GetLstFile() const noexcept {
    return lst_file_;
  }

  /// \brief Дополняет список директорий.
  /// \param[in] path Путь до директории.
  void SetLstDir(const std::string &dpath);
  void SetLstDir(std::string &&dpath);

  /// \brief Возвращает список директорий.
  /// \return Путь до директории.
  std::vector<std::string> GetLstDir() const noexcept {
    return lst_dir_;
  }

 private:
  std::vector<std::string> lst_file_{};
  std::vector<std::string> lst_dir_{};
  
};
}   // namespace security_self_tests
}   // namespace fintech
#endif  // SELINUX_SELF_TEST_PARSER_SELINUX_SELF_TEST_PARSER_H_

