#include <iostream>
#include <fstream>
#include "log_print_handler.h"

void PrintConsoleObj::Print(const std::string& log_message) {
  std::cerr << log_message;
}

void PrintFileObj::Print(const std::string& log_message) {
  if (log_file_.empty()) {
    PrintConsoleObj pc;
    pc.Print(log_message);
    return;
  }

  std::ofstream ofs(log_file_, std::ios_base::app | std::ios_base::binary);
  if (ofs.is_open()) {
    ofs << log_message;
  } else {
    PrintConsoleObj pc;
    pc.Print("log file open failed!\n");
  }
  ofs.close();
}