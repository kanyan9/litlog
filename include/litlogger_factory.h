#pragma once

#include <string>
#include "litlogger.h"
#include "litlog_config.h"
#include "log_format_handler.h"
#include "log_print_handler.h"

#define LIT_LOG_INTERNAL() \
  LitloggerFactory::Instance()

#define LIT_LOG_INIT(configuration) \
  LIT_LOG_INTERNAL().Init(configuration);

#define LIT_LOG(level, message) \
  LIT_LOG_INIT("../config/log_config.json") \
  LIT_LOG_INTERNAL().get_logger().Logging(LitlogLevel::level, message, __FILE__, __LINE__)

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