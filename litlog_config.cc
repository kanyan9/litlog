#include "litlog_config.h"
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

void LitlogConfig::JsonConfigParse(const std::string& config_file) {
  std::ifstream jf(config_file);
  if (!jf.is_open()) {
    std::cerr << "log config file open failed!" << std::endl;
    return;
  }

  json data = json::parse(jf);
  
  for (auto& item : data.items()) {
    config_[item.key()] = item.value();
  }
}

std::string LitlogConfig::get(const std::string& key) {
  if (config_.find(key) != config_.end())
    return config_[key];
  
  return "";
}