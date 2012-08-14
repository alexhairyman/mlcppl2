#include "arcy.hh"
#include <string>
#include <iostream>
#include <boost/filesystem.hpp>

using namespace std;
using namespace boost::filesystem;

int main()
{
  ml::arcfile * testarc = new ml::arcfile(ml::M_READ, ml::ARCT_USTAR);
  ml::arcent * testent = new ml::arcent;
  testent->write("'Ello there");
  testent->setpath("hello.txt");
  
  if (exists(*(new path("../test1.tar"))))
    cout << "../test1.tar exists" << '\n';
  else
    cout << "../test1.tar does not exist" << '\n';
  
  cout << current_path() << '\n';
  
  testarc->setfilename("../test1.tar");
  testarc->dozip();
  testarc->getentries();
  cout << testarc->readentry(0).getpath() << '\n';
}
