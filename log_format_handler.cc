#include <iostream>
#include <sstream>
#include <chrono>
#include "log_format_handler.h"

std::string LogFormat::Format(const std::string& level,
                              const std::string& log_message,
                              const std::string& filename,
                              const int line) {
    
    std::stringstream ss;
    std::chrono::system_clock::time_point sys_time = std::chrono::system_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(sys_time);
    std::string time_str = std::ctime(&time);

    ss << time_str.substr(0, time_str.size() - 1) << " " << "[" << level << "]" << " " << log_message << " " << filename << " " << line << "\n";

    return ss.str();
}