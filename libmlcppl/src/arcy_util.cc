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
  arc_fmt_ptr __delegate_correct_read_ptr(ARC_T atype)
  {
    arc_fmt_ptr pta;
    if (atype == ARCT_7Z)
      pta = &archive_read_support_format_7zip;
    else if (atype == ARCT_ISO)
      pta = &archive_read_support_format_iso9660;
    else if (atype == ARCT_PAX || atype == ARCT_USTAR)
      pta = &archive_read_support_format_tar;
    else if (atype == ARCT_ZIP)
      pta = &archive_read_support_format_zip;
      
    return pta;
  }

  arc_fmt_ptr __delegate_correct_write_ptr(ARC_T atype)
  {
    arc_fmt_ptr pta;
    if (atype == ARCT_7Z)
      pta = &archive_write_set_format_7zip;
    else if (atype == ARCT_ISO)
      pta = &archive_write_set_format_iso9660;
    else if (atype == ARCT_PAX)
      pta = &archive_write_set_format_pax_restricted;
    else if (atype == ARCT_USTAR)
      pta = &archive_write_set_format_ustar;
    else if (atype == ARCT_ZIP)
      pta = &archive_write_set_format_ustar;
    
    return pta;
  }

  arc_fmt_ptr get_correct_arcptr(ARC_T atype, MODE _mode)
  {
    if (_mode == M_READ)
      return __delegate_correct_read_ptr(atype);
    else if (_mode == M_WRITE)
      return __delegate_correct_write_ptr(atype);
  }
  
  void catcherr(ARC_ERR ae)
  {
    if (ae == ERR_BADMODE)
      {
        cerr << "BAD MODE FOR ARCFILE " << endl;
      }
  }
  
}
