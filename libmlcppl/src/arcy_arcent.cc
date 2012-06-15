/*
Copyright (c) <2012> alex herrmann (alexhairyman@gmail.com)

Permission is hereby granted, free of charge, to any person 
obtaining a copy of this software and associated documentation 
files (the "Software"), to deal in the Software without 
restriction, including without limitation the rights to use, copy, 
modify, merge, publish, distribute, sublicense, and/or sell copies 
of the Software, and to permit persons to whom the Software is 
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be 
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF 
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND 
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS 
BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN 
ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN 
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE 
SOFTWARE.
*/
#include "arcy.hh"

namespace ml
{
  arcent::arcent()
  {
    _archive_entry = archive_entry_new();
    _datas = new string();
    _mdata = new stringbuf();
    _dataw = new iostream(_mdata);

  }
  
  // Path stuffs
  void arcent::setpath(string path)
  {
    archive_entry_set_pathname(_archive_entry, path.c_str());
  }
  
  string arcent::getpath()
  {
    string s;
    s.assign(archive_entry_pathname(_archive_entry));
    return s;
  }
  
  // size stuffs
  bool arcent::sizeisset()
  {
    if (archive_entry_size_is_set(_archive_entry) != 1)
      return false;
    else
      return true;
  }
  
  void arcent::setsize(int size)
  {
    archive_entry_set_size(_archive_entry, size);
  }
  
  int arcent::getsize()
  {
    return archive_entry_size(_archive_entry);
  }
  
  // data writing
  
  void arcent::addchar(char x)
  {
    _mdata->str().push_back(x);
  }
  
  void arcent::write(char *data)
  {
    _datas->append(data);
  }
  
  void arcent::write(const char *data)
  {
    _datas->append(data);
  }
  
  void arcent::write(string data)
  {
    _datas->append(data);
  }
  
}
