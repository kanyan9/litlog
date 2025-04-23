#include <iostream>
#include <string>
#include "log_format_handler.h"
#include "log_print_handler.h"
#include "litlogger.h"

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
  LitLogger ll(LitlogLevel::INFO, __FILE__, __LINE__);
  ll.set_log_message("Hello Litlog!");
  ll.set_log_format(new LogFormat());
  // ll.set_log_print(new PrintConsoleObj());
  ll.set_log_print(new PrintFileObj("/tmp/log2"));
  ll.Logging();
  
  return 0;
}