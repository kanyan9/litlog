#pragma once

#include <string>
#include "litlogger.h"
#include "log_format_handler.h"
#include "log_print_handler.h"

class LitloggerFactory {
public:
  static LitloggerFactory& Instance() {
    static LitloggerFactory fac;
    return fac;
  }

  void Init(const std::string& log_config_file);

  Litlogger& get_logger() { return logger_; }

private:
  LitloggerFactory() = default; 
  Litlogger logger_;
};