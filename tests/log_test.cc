#include <iostream>
#include <string>
// #include "log_format_handler.h"
// #include "log_print_handler.h"
// #include "litlogger.h"
#include "litlogger_factory.h"
// #include "litlog_config.h"

using namespace std;

int main(int argc, char** argv) {
  // logformat test
  // LogFormat lf;
  // string str = lf.Format("DEBUG", "Hello Litlog!", __FILE__, __LINE__);
  // cout << str;

  // logprint console
  // PrintConsoleObj pc;
  // pc.Print(str); 

  // logprint file
  // PrintFileObj pf("/tmp/log");
  // pf.Print(str);

  // litlogger test
  // Litlogger ll;
  // ll.set_log_format(new LogFormat());
  // ll.set_log_print(new PrintConsoleObj());
  // ll.set_log_print(new PrintFileObj("/tmp/log2"));
  // ll.set_level_threshold(LitlogLevel::ERROR);
  // ll.Logging(LitlogLevel::INFO, "Hello Litlog!", __FILE__, __LINE__);

  // litlog factory test
  // LitloggerFactory::Instance().Init("config/log_config");
  // LitloggerFactory::Instance().get_logger().Logging(LitlogLevel::DEBUG, "Hello Litlog!", __FILE__, __LINE__);
  
  // litlog config test
  // LitlogConfig config;
  // config.JsonConfigParse("../config/log_config.json");

  // litlog marco test
  LIT_LOG(INFO, "Hello Litlog!");
  
  return 0;
}