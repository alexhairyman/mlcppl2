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

/**
 * @defgroup EVALIF evaluate if these are necessary
 * @{
 */

/**
 * @page ARENEC are these necessary?
 * Are all these really necessary to keep in the code? or do they just mess everything up?
 */
/// @}

#pragma once

#ifndef __ARCY_INC
#define __ARCY_INC

#include "mlcppl2.hh"
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

//~ #ifdef __TEST_PP
  #define __OUTFUNC(a) std::cout << #a << std::endl
  #define __OUT(a) std::cout << #a << ": " << a << std::endl
  #define OUT(b) __OUT(b)
//~ #endif

using namespace std;

/**
 * @brief The main mlcppl namespace
 * 
 * The main namespace where everything can be found
 * As of right now, the std namespace is not modified
 *
 */
namespace ml
{
  /** 
   * @defgroup ARCY Arcy libarchive c++ wrapper
   * @{
   */
  
  /**
   * @page libarchive LibArchive
   * libarchive is A c library, it can be found <a href="https://github.com/libarchive/libarchive"> here </a>
   * It was built to manipulate archives on the Bsd platform and has evolved into a mature,
   * cross-platform, and very useful library, it supports many different types of archives
   * to find out more about for you self you can visit it at the link above. If it is ever
   * updated, and my build breaks, I will try my hardest to get it working again, although
   * it's not as if I'm using any crazy experimental features of the library!
   */
  
  /**
   * @page libarchive_notes Notes
   * LibArchive builds on Windows platforms, and even comes with a CMake file that
   * produces a working (building) VS2010 solution, so if you can't get the binaries
   * I will (hopefully, no promises though) include in the future to work, I will
   * be glad to help you out if necessary
   */
  
  /// mode for the archive
  enum MODE
  {
    M_NONE=0, ///< no mode
    M_READ=1, ///< read mode
    M_WRITE=2 ///< write mode
  };

  /// type of archive, and it's callbacks
  enum ARC_T
  {
    ARCT_NONE=0, ///< no archive chosen
    ARCT_ZIP=1, ///< plain old Zip archiv
    ARCT_PAX=2, ///< pax tar archive
    ARCT_USTAR=3, ///< ustar tar archive
    ARCT_7Z=4, ///< 7zip archive
    ARCT_ISO=5 ///< ISO9660 archive/image
  };

  /**
   * @brief a function pointer for libarchive open() functions
   */
  typedef int (*arc_fmt_ptr)(struct archive*);
  // typedef int (*readptr)(struct archive*, const char*, int);
  
  
  /**
   * @returns correct read pointer
   * @brief gets the good read pointer for atype
   */
  arc_fmt_ptr __delegate_correct_read_ptr(ARC_T atype);
  
  /// @returns correct write pointers
  /// @brief gets the good write pointer
  arc_fmt_ptr __delegate_correct_write_ptr(ARC_T atype);
  
  /**
   * @brief gets the correct pointer
   * Will hopefully get the correct pointer
   * Uses these delegate functions to do the real work
   * @see __delegate_correct_read_ptr() __delegate_correct_write_ptr()
   * @param atype specify the type
   * @param _mode specify the mode
   * @see ARC_T MODE
   */
  arc_fmt_ptr get_correct_arcptr(ARC_T atype, MODE _mode);
  
  /// Will specify compression in the future
  enum COMP_T
  {
    COMPT_NONE=0,
    COMPT_GZIP=1,
    COMPT_BZIP2=2,
    COMPT_LZMA=3
  };
  
  /**
   * @defgroup ARCENT archive_entry wrapper
   * @{
   */
  
  /**
   * @brief An archive entry
   *
   * Archive entry, no mode is specified because it is not needed.
   * this class is the wrapper around libarchive's archive_entry
   */
  class arcent
  {
  public:
    
    /**
     * @brief sets up the archive_entry object
     */
    arcent();
    
    /**
     * @brief set the pathname in the archive entry
     * @param path path to set to
     */
    void setpath(string path);
    /**
     * @brief get the pathname for the archive_entry
     * @returns a string of the path
     */
    string getpath();
    
    /**
     * @brief set the size
     * @param size the size to set to
     */
    void setsize(int size);
    
    /**
     * @brief get the size
     * @returns the size of the archive_entry object
     */
    int getsize();
    
    /**
     * @brief figure the size 
     * @returns the figured size
     */
    int figuresize();
    
    /**
     * @brief find out if the size is set
     */
    bool sizeisset();
    
    /** @defgroup POSIX_SPEC POSIX specific stuff for right now
     * @todo add documentation
     * @{
     */
    
    void setperms(string perms);
    string getperms();
    
    void setbtime(int time);
    int getbtime();
    
    void setmtime(int time);
    int getmtime();
    
    void setctime(int time);
    int getctime();
    /// @}
    
    /**
     * @brief add a character
     */
    void addchar(char x);
    
    /**
     * @brief write a std::string
     */
    void write(string data);
    
    /**
     * @brief write a char *
     */
    void write(char * data);
    
    /**
     * @brief write a const char*
     */
    void write (const char * data);
    
    /**
     * @brief return the libarchive archive_entry
     * @returns the libarchive archive_entry
     */
    archive_entry* getarcent();
    
  private:
    
    /**
     * @addtogroup EVALIF
     */
    /// @{
    stringbuf* _mdata;
    iostream* _dataw;
    /// @}
    
    string* _datas;
    
    /// @addtogroup EVALIF
    
    /// @{
    string _path; ///< path
    bool _path_set; ///< is path set
    
    string _perms; ///< POSIX permissions
    
    int _size; ///< size 
    bool _size_set; ///< is size set
    
    int _mtime; ///< mod time
    int _btime; ///< birth time
    int _ctime; ///< created time
    /// @}
    
    struct archive_entry* _archive_entry;
  };
  /// @}
  
  /**
   * @defgroup ARCFILE archive wrapper
   * @{
   */
  
  /**
   * @brief An archive file
   *
   * Maybe in the future I will add a way to switch them so you can
   * change modes
   * @warning BROKEN!
   */
  class arcfile
  {
  public:
    
    /**
     * @brief create archive with a mode
     * @param mode mode to use archive with
     */
    arcfile(MODE mode);
    
    /**
     * @brief create archive with a mode and a type
     * @param mode mode to use archive with
     * @param type type to use archive with
     */
    arcfile(MODE mode, ARC_T type);
    ~arcfile();
    
    void addentry(arcent entry);
    arcent readentry(int location);
    
    void settype(ARC_T type);
    
    void setfilename(string filename);
    
  private:
    void initarch(MODE mode = M_NONE, ARC_T type = ARCT_NONE);
    arc_fmt_ptr correct_open_func;
  
    struct archive* _archive;
    
    bool isinitialized;
    bool noerror;
    
    MODE _mode;
    ARC_T _type;

  };
  /// @}
  /// @}
}

#endif
