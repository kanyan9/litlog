#include "litlogger_factory.h"

std::unique_ptr<Litlogger> LitloggerFactory::get_logger(LitlogLevel level,
                                      const std::string& filename,
                                      const int line) {
  std::unique_ptr<Litlogger> logger;
  logger = std::make_unique<Litlogger>(level, filename, line);

  logger->set_log_format(std::make_unique<LogFormat>());

  LitlogConfig config;
  config.JsonConfigParse(log_config_file_);
  if (config.get("log_type") != "file") {
    logger->set_log_print(std::make_unique<PrintConsoleObj>());
  } else {
    if (config.get("log_file") == "") {
      logger->set_log_print(std::make_unique<PrintFileObj>("/tmp/log"));
    }
    logger->set_log_print(std::make_unique<PrintFileObj>(config.get("log_file")));
  }

  int log_level_threshold =std::stoi(config.get("log_level_threshold"));
  switch (log_level_threshold) {
    case 0:
      logger->set_level_threshold(LitlogLevel::DEBUG);
      break;
    case 1:
      logger->set_level_threshold(LitlogLevel::INFO);
      break;
    case 2:
      logger->set_level_threshold(LitlogLevel::ERROR);
      break;
    case 3:
      logger->set_level_threshold(LitlogLevel::FATAL);
      break;
    default:
      break;
  }

  return logger;
}