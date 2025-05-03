#pragma once

#include <iostream>
#include <string>
#include <memory>
#include "litlog_format.h"
#include "litlog_print.h"

const int kMaxLogMessageLen = 30000;

enum class LitlogLevel {
  DEBUG = 0,
  INFO = 1,
  ERROR = 2,
  FATAL = 3 
};

// refer to the glog to implement logging APIs based on C++-style streams 
class LitlogStreamBuf : public std::streambuf {
public:
  LitlogStreamBuf(char* buf, int len) {
    setp(buf, buf + len - 2);
  }

  ~LitlogStreamBuf() {} 

  // This effectively ignores overflow.
  int_type overflow(int_type ch) { return ch; }

  // Legacy public ostream method.
  size_t pcount() const { return static_cast<size_t>(pptr() - pbase()); }
  char* pbase() const { return std::streambuf::pbase(); }
};

class LitlogStream : public std::ostream {
public:
  LitlogStream(char* buf, int len)
      : std::ostream(nullptr), streambuf_(buf, len), self_(this) {
    rdbuf(&streambuf_);
  }

  LitlogStream(LitlogStream&& other) noexcept
      : std::ostream(nullptr),
      streambuf_(std::move(other.streambuf_)),
      self_(this) {
    rdbuf(&streambuf_);
  }

  LitlogStream& operator=(LitlogStream&& other) noexcept {
    streambuf_ = std::move(other.streambuf_);
    rdbuf(&streambuf_);
    return *this;
  }

  ~LitlogStream() {}

  // Legacy std::streambuf methods.
  size_t pcount() const { return streambuf_.pcount(); }
  char* pbase() const { return streambuf_.pbase(); }
  char* str() const { return pbase(); }

  LitlogStream(const LitlogStream&) = delete;
  LitlogStream& operator=(const LitlogStream&) = delete;

  std::streambuf* get_streambuf() { return &streambuf_; }

private:
  LitlogStreamBuf streambuf_;
  LitlogStream* self_;
};

class LitlogMessage {
public:
  LitlogMessage() : stream_(log_message_text_, kMaxLogMessageLen) {}
  ~LitlogMessage() {}

  char log_message_text_[kMaxLogMessageLen + 1] = "";

  LitlogMessage(const LitlogMessage&) = delete;
  LitlogMessage& operator=(const LitlogMessage&) = delete;

  LitlogStream stream_;
};

class Litlogger {
public:
  Litlogger() = default;

  Litlogger(LitlogLevel level, const std::string& filename, const int line)
      : level_(level), filename_(filename), line_(line) {}
 
  void set_log_file(const std::string& log_file) { log_file_ = log_file; }
  void set_log_format(std::unique_ptr<LitlogFormat> log_format) { log_format_ = std::move(log_format); }
  void set_log_print(std::unique_ptr<LitlogPrint> log_print) { log_print_ = std::move(log_print); }
  void set_level_threshold(LitlogLevel level_threshold) { level_threshold_ = level_threshold; }

  std::ostream& Stream() { return log_message_.stream_; }

  void Logging();

  ~Litlogger() { 
    Logging();
  }

private:
  LitlogMessage log_message_;

  LitlogLevel level_;
  std::string filename_;
  int line_;

  std::string log_file_; 
  LitlogLevel level_threshold_ = LitlogLevel::DEBUG;

  std::unique_ptr<LitlogFormat> log_format_;
  std::unique_ptr<LitlogPrint> log_print_;
};