#include "arcy.hh"
#include <string>
#include <iostream>
#include <boost/filesystem.hpp>

using namespace ml;
using namespace std;
using namespace boost::filesystem3;

int main()
{
  arcfile * testarc = new arcfile(M_READ, ARCT_USTAR);
  
  if (exists(*(new path("../test1.tar"))))
    cout << "../test1.tar exists" << '\n';
  else
    cout << "../test1.tar does not exist" << '\n';
  
  testarc->setfilename("../test1.tar");
  testarc->dozip();
  testarc->getentries();
  cout << testarc->readentry(0).getpath() << '\n';
}
