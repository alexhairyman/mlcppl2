#include "derpp.hh"
#include "msutil.hh"

using namespace std;

/*
const char* mlcppl::noreaderr::what() const throw()
{
  return "no read permissions";
}
*/

namespace ml
{
  bool testreadsearch(string path)
  {
    if (access(path.c_str(), R_OK | X_OK) == 0)
      {
        return true;
      }
    else
      {
        return false;
      }
  }
  
  derpp::derpp(string path)
  {
    try
    {
      if  (testreadsearch(path) == true)
        {
          cur_path = path;
        }
      else
        {
          throw norerr;
        }
    }
    catch (int i)
    {
      print("ARGGGJHH");
    }
  }
  
  bool derpp::setdir(string path)
  {
    try
    {
      if (testreadsearch(path) == true)
        {
          cur_path = path;
          return true;
        }
      else
        {
          throw norerr;
        }
    }
    catch(int i)
    {
      print("ARGGGHHHH");
    }
  }
  
  vector<string> derpp::listfiles()
  {
    vector<string> fls;
    diritr = opendir(cur_path.c_str());
    if (diritr != NULL)
      {
        while (dirlistr = readdir(diritr))
          {
            fls.insert(fls.begin(), dirlistr->d_name);
          }
        (void) closedir (diritr);
      }
    return fls;
    
  }
}
