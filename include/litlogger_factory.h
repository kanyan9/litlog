#pragma once

#include <string>
#include <memory>
#include "litlogger.h"
#include "litlog_config.h"
#include "log_format_handler.h"
#include "log_print_handler.h"

#define LIT_LOG_INTERNAL() \
  LitloggerFactory::Instance()

#define LIT_LOG_INIT(configuration) \
  LIT_LOG_INTERNAL().set_log_config_file(configuration)

#define LIT_LOG(level) \
  LIT_LOG_INTERNAL().get_logger(LitlogLevel::level, __FILE__, __LINE__)->Stream()

class LitloggerFactory {
public:
  static LitloggerFactory& Instance() {
    static LitloggerFactory fac;
    return fac;
  }

  void set_log_config_file(const std::string& log_config_file) {
    log_config_file_ = log_config_file;
  }

  std::unique_ptr<Litlogger> get_logger(LitlogLevel level, const std::string& filename, const int line);

private:
  std::string log_config_file_ = "../config/log_config.json";
  LitloggerFactory() = default;
  ~LitloggerFactory() = default;
};