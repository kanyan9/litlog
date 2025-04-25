#include "litlogger.h"

void Litlogger::Logging(LitlogLevel level,
                        const std::string& log_message,
                        const std::string& filename,
                        int line) {
  if (level < level_threshold_)
    return;

  std::string level_str;
  switch (level)
  {
  case LitlogLevel::INFO:
    level_str = "INFO";
    break;
  case LitlogLevel::ERROR:
    level_str = "ERROR";
    break;
  case LitlogLevel::FATAL:
    level_str = "FATAL";
  default:
    level_str = "DEBUG";
    break;
  }
  auto fmt_log = log_format_->Format(level_str, log_message, filename, line);
  log_print_->Print(fmt_log);
}