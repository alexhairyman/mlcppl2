#include "arcy.hh"

int main(int argc, char** argv)
{
  string * filename;
  
  if (argc < 2)
    return 1;
    
  char* arg1 = argv[1];
  filename = new string(arg1);
  O(*filename);
  string x = ml::readfilename(*filename);
  O(x);
}
