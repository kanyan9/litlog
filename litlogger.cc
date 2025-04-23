#include "litlogger.h"

void LitLogger::Logging() {
  std::string level_str;
  switch (level_)
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
  auto fmt_log = log_format_->Format(level_str, log_message_, file_name_, line_);
  log_print_->Print(fmt_log);
}