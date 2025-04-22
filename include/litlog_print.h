#include "log_print.h"

class LitlogPrintConsole : public LogPrint {
public:
  void Print(const std::string& log);
};

class LitlogPrintFile : public LogPrint {
public:
  void Print(const std::string& log);
  void SetLogFile(const std::string& filename);

private:
  std::string log_file_ = "";
};