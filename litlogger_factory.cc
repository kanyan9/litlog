#include "litlogger_factory.h"

void LitloggerFactory::Init(const std::string& log_config_file) {
  logger_.set_log_format(std::make_unique<LitlogFormat>());

  LitlogConfig config;
  config.JsonConfigParse(log_config_file);
  if (config.get("log_type") != "file") {
    logger_.set_log_print(std::make_unique<PrintConsoleObj>());
  } else {
    if (config.get("log_file") == "") {
      logger_.set_log_print(std::make_unique<PrintFileObj>("/tmp/log"));
    }
    logger_.set_log_print(std::make_unique<PrintFileObj>(config.get("log_file")));
  }

  int log_level_threshold =std::stoi(config.get("log_level_threshold"));
  switch (log_level_threshold) {
    case 0:
      logger_.set_level_threshold(LitlogLevel::DEBUG);
      break;
    case 1:
      logger_.set_level_threshold(LitlogLevel::INFO);
      break;
    case 2:
      logger_.set_level_threshold(LitlogLevel::ERROR);
      break;
    case 3:
      logger_.set_level_threshold(LitlogLevel::FATAL);
      break;
    default:
      break;
  }
  
}