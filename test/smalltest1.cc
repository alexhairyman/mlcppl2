#include "arcy.hh"

int main()
{
  using namespace ml;
  arcent ae1;
  OUT(ae1.sizeisset());
  ae1.setsize(500);
  OUT(ae1.sizeisset());
  ae1.setpath("Hello_ladies");
  OUT(ae1.getpath());
  OUT(ae1.getsize());
}
