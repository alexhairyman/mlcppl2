#include "mlslos/mlarray.hh"
#include <cstdio>
#include <string>

int main()
{
  puts("Beginning test:\n");

  ml::los::mlArray<char> chararray;
  chararray.AddAt('a', 0);
  chararray.AddAt('b', 1);

  putchar(chararray.GetAt(1));
  putchar(chararray.GetAt(0));
  puts("\n"); // yes, I want 2 endlines here


  ml::los::mlArray<std::string> strarray;
  strarray.AddAt("World", 0);
  strarray.AddAt("Hello big",1);

  puts(strarray.GetAt(1).c_str());
  puts(strarray.GetAt(0).c_str());

  puts("\nRemoving Hello big, and replacing with Goodbye");

  strarray.DelAt(0);
  strarray.AddAt("Goodbye", 0);

  puts("attempting to output the strings\n");
  puts(strarray[1].c_str());
  puts(strarray[0].c_str());

  putchar('\n');

  puts("End of test");

  return 0;
}
