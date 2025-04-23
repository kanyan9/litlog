#include "litlog_print.h"

class PrintConsoleObj : public LitlogPrint {
public:
  void Print(const std::string& log_message);
};

class PrintFileObj : public LitlogPrint {
public:
  PrintFileObj(const std::string& log_file) : log_file_(log_file) {}
  void Print(const std::string& log_message);

private:
  std::string log_file_;
};