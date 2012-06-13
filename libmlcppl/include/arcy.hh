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

#pragma once

// libarchive includes
#include <archive.h>
#include <archive_entry.h>

// Standard Library include
#include <string>
#include <iostream>
#include <sstream>

// STL container includes
// Do I really need map?
#include <vector>
#include <list>
#include <deque>

#ifdef __TEST_PP
  #define __OUTFUNC(a) std::cout << #a << std::endl
  #define __OUT(a) std::cout << #a << ": " << a << std::endl
#endif

using namespace std;

namespace ml
{
  
  // mode for the archive
  enum MODE
  {
    M_NONE=0,
    M_READ=1,
    M_WRITE=2
  };

  // type of archive, and it's callbacks
  enum ARC_T
  {
    ARCT_NONE=0,
    ARCT_ZIP=1,
    ARCT_PAX=2,
    ARCT_USTAR=3,
    ARCT_7Z=4,
    ARCT_ISO=5
  };
  // vectors of function pointers
  typedef int (*arc_fmt_ptr)(struct archive*);
  // typedef int (*readptr)(struct archive*, const char*, int);
  
  
  arc_fmt_ptr __delegate_correct_read_ptr(ARC_T atype);
  arc_fmt_ptr __delegate_correct_write_ptr(ARC_T atype);
  
  arc_fmt_ptr get_correct_arcptr(ARC_T atype, MODE _mode);
  
  // Not really used for anything yet
  enum COMP_T
  {
    COMPT_NONE=0,
    COMPT_GZIP=1,
    COMPT_BZIP2=2,
    COMPT_LZMA=3
  };
  
  class arcent
  {
  public:
    // archive_entry stuff
    arcent();
    
    void setpath(string path);
    string getpath();
    
    void setsize(int size);
    int getsize();
    int figuresize();
    bool sizeisset();
    
    void setperms(string perms="0644");
    string getperms();
    
    void setbtime(int time);
    int getbtime();
    
    void setmtime(int time);
    int getmtime();
    
    void setctime(int time);
    int getctime();
    
    void addchar(char x);
    void write(string data);
    void write(char * data);
    void write (const char * data);
    
    archive_entry* getarcent();
    
  private:
  
    stringbuf* _mdata;
    iostream* _dataw;
    
    string _path;
    bool _path_set;
    
    string _perms;
    
    int _size;
    bool _size_set;
    
    int _mtime;
    int _btime;
    int _ctime;
    
    struct archive_entry* _archive_entry;
  };
  
  /*
   * an archive file
   * you must specify a mode because an archive can only read or write,
   * not both though
   */
   
  /*
   * Maybe in the future I will add a way to switch them so you can
   * change modes
   */
  class arcfile
  {
  public:
    arcfile(MODE mode);
    ~arcfile();
    
    void addentry(arcent entry);
    arcent readentry(int location);
    
    void setfilename(string filename);
    
  private:
    arc_fmt_ptr correct_open_func;
  
    struct archive* _archive;
    
    bool isinitialized;
    bool noerror;
    
    MODE _mode;
    
  };
}
