#include "log_format.h"

class LitlogFormat : public LogFormat {

public:
  std::string Format(
    const std::string& level,
    const std::string& msg,
    const std::string& filename,
    const int line
  );

  virtual ~LitlogFormat() {}
};