#include <dirent.h>
#include <unistd.h>
#include <string>
#include <vector>

#ifndef __DERPP
#define __DERPP

using namespace std;

#define norerr 3
namespace ml
{
  class derpp
  {
  public:
    derpp(string path);
    bool setdir(string path);
    vector<string> listfiles();
    
  private:
    string cur_path;
    DIR * diritr;
    dirent * dirlistr;
    
  };
  
}
#endif
