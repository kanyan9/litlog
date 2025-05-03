#include "litlogger.h"

void Litlogger::Logging() {
  if (level_ < level_threshold_)
    return;

  std::string level_str;
  switch (level_) {
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
  std::string log_message_str(log_message_.log_message_text_);
  auto fmt_log = log_format_->Format(level_str, log_message_str, filename_, line_);
  log_print_->Print(fmt_log);
}