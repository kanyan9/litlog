#include "litlogger_factory.h"

void LitloggerFactory::Init(const std::string& log_config_file) {
  logger_.set_log_format(new LogFormat());
  logger_.set_log_print(new PrintConsoleObj());
}