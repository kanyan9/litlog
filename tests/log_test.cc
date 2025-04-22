#include <iostream>
#include <string>
#include "litlog_format.h"

using namespace std;

int main(int argc, char** argv) {
  // litlogformat test
  LitlogFormat lf;
  string str = lf.format("DEBUG", "Hello log!", __FILE__, __LINE__);
  cout << str;
  
  return 0;
}