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

class LitLogger {
public:
  LitLogger(LitlogLevel level,
            const std::string& filename,
            int line) : level_(level), file_name_(filename), line_(line) {}
 
  
  void set_log_message(const std::string& log_message) { log_message_ = log_message; }
  void set_log_file(const std::string& log_file) { log_file_ = log_file; }
  void set_log_format(LitlogFormat* log_format) { log_format_ = log_format; }
  void set_log_print(LitlogPrint* log_print) { log_print_ = log_print; }

  void Logging();

private:
  LitlogLevel level_ = LitlogLevel::DEBUG;
  std::string file_name_; 
  int line_;

  std::string log_message_;

  std::string log_file_ = ""; 

  LitlogFormat* log_format_ = nullptr;
  LitlogPrint* log_print_ = nullptr;
};