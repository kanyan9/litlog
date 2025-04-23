#include "litlog_format.h"

class LogFormat : public LitlogFormat {

public:
  std::string Format(
    const std::string& level,
    const std::string& msg,
    const std::string& filename,
    const int line
  );

  virtual ~LogFormat() {}
};