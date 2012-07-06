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
#define __ARCY_INC
#include "arcy.hh"

namespace ml
{
  
  /** @todo implement all this stuff */
  void arcfile::dozip()
  {
#warning "IMPLEMENT THIS CRAPOLA"
    
  }

  void arcfile::getentries()
  {
    OFR
    archive_entry* _temphead;
    arcent * _temparcent;
    while (archive_read_next_header(_archive, &_temphead) == ARC_OK)
    {
      _temparcent = new arcent(_temphead);
      _ents.push_back(*_temparcent);
      delete _temparcent;
    }
  }

  void arcfile::initarch(MODE mode, ARC_T type)
  {
    _mode = mode;
    _type = type;
    _data = new string();
    
    if (_type != ARCT_NONE)
      correct_format_func = get_correct_arcptr(_type, _mode);
    
    if (_mode == M_READ)
      _archive = archive_read_new();
    else if (_mode == M_WRITE)
      _archive = archive_write_new();
    
    archive_read_open(_archive, this, &archive_read_string_open, &archive_string_read_cb, &archive_string_close_cb);
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
  
  void arcfile::setdata(string data)
  {
    _data->assign(data);
  }
  
  void arcfile::setdata(char *data)
  {
    _data->assign(data);
  }
  
  void arcfile::setfilename(string filename)
  {
    _filename.assign(filename);
  }
  
  char arcfile::readbyte()
  {
    return _data->at(_numread);
    _numread++;
  }

  rcb_ret arcfile::read_cb()
  {
    char tempchar = readbyte();
    int tempnum = _numread;
    
    rcb_ret newret;
    
    newret.howmanyread = tempnum;
    *(newret.tehrealzdata) = tempchar;
    
    return newret;
  }
  
}
