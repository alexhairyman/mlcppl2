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
  
  void arcfile::initarch(MODE mode, ARC_T type)
  {
    _mode = mode;
    _type = type;
    if (_mode == M_READ)
      _archive = archive_read_new();
    else if (_mode == M_WRITE)
      _archive = archive_write_new();  
    
    if (_type != ARCT_NONE)
      correct_open_func = get_correct_arcptr(_type, _mode);
    
  }

  arcfile::arcfile(MODE mode)
  {
    initarch(mode, ARCT_NONE);
  }
  
  arcfile::arcfile(MODE mode, ARC_T type)
  {
    initarch(mode, type);
  }
  
  void arcfile::addentry(arcent entry)
  {
    OFW
    _ents.push_back(entry);
  }
  
  arcent arcfile::readentry(int location)
  {
    OFR
    return _ents.at(location);
  }
  
}
