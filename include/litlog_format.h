#pragma once

#include <string>

class LitlogFormat {

public:
  virtual std::string Format(
    const std::string& level,
    const std::string& msg,
    const std::string& filename,
    const int line 
  ) = 0;

};