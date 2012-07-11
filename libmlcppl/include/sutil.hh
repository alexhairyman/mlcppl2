#include <iostream>

#ifndef __SUTIL
#define __SUTIL

using namespace std;
namespace ml
{
  template<typename t> void print(t toprint)
  {
    cout << toprint << '\n';
    cout.flush();
  }
  
  struct serr
  {
    int serrnum;
    string msg;
    void printmsg();
  };
}


#endif
