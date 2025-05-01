#pragma once

#include <string>
#include <map>

class LitlogConfig {
public:
  LitlogConfig() = default;

  void JsonConfigParse(const std::string& config_file);

  std::string get(const std::string& key);

private:
  std::map<std::string, std::string> config_;
};