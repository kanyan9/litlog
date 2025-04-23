#pragma once

#include <string>

class LitlogPrint {
public:
  virtual void Print(const std::string& log) = 0;
};