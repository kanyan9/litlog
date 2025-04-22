#include <iostream>
#include <fstream>
#include "litlog_print.h"

void LitlogPrintConsole::Print(const std::string& log) {
  std::cout << log;
}

void LitlogPrintFile::Print(const std::string& log) {
  if (log_file_.empty()) {
    LitlogPrintConsole pc;
    pc.Print(log);
    return;
  }

  std::ofstream ofs(log_file_, std::ios_base::app | std::ios_base::binary);
  if (ofs.is_open()) {
    ofs << log;
  } else {
    LitlogPrintConsole pc;
    pc.Print("log file open failed!\n");
  }
  ofs.close();
}

void LitlogPrintFile::SetLogFile(const std::string& filename) {
  this->log_file_ = filename;
}
