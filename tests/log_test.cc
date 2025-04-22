#include <iostream>
#include <string>
#include "litlog_format.h"
#include "litlog_print.h"

using namespace std;

int main(int argc, char** argv) {
  // litlogformat test
  LitlogFormat lf;
  string str = lf.format("DEBUG", "Hello log!", __FILE__, __LINE__);
  // cout << str;

  // litlogprint console
  // litlogPrintConsole pc;
  // pc.Print(str); 

  // litlogprint file
  LitlogPrintFile pf;
  pf.SetLogFile("/tmp/log.txt");
  pf.Print(str);

  
  return 0;
}