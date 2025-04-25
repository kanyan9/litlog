#pragma once

#include <string>
#include "litlog_format.h"
#include "litlog_print.h"

enum class LitlogLevel {
  DEBUG = 0,
  INFO = 1,
  ERROR = 2,
  FATAL = 3 
};

class Litlogger {
public:
  Litlogger() = default;
 
  void set_log_file(const std::string& log_file) { log_file_ = log_file; }
  void set_log_format(LitlogFormat* log_format) { log_format_ = log_format; }
  void set_log_print(LitlogPrint* log_print) { log_print_ = log_print; }
  void set_level_threshold(LitlogLevel level_threshold) { level_threshold_ = level_threshold; }

  void Logging(LitlogLevel level,
               const std::string& log_message,
               const std::string& filename,
               int line);

private:
  std::string log_file_ = ""; 
  LitlogLevel level_threshold_ = LitlogLevel::DEBUG;

  LitlogFormat* log_format_ = nullptr;
  LitlogPrint* log_print_ = nullptr;
};