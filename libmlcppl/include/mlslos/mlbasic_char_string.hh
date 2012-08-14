#ifndef ML_CHARSTRING_HH
#define ML_CHARSTRING_HH

#ifndef NOSTL
#include <string>
#endif

#include "mlslos/mlarray.hh"
#include "mlslos/mlcollection.hh"
namespace ml
{
  namespace los
  {
    /** @todo provide more constructors
     *  @todo find out if the mlArray class will actually do what I need efficiently */
    /** Basic string class, not a template only works with basic chars for now */
    class mlCharString : mlCollection
    {
    public:
      mlCharString();
      friend bool operator== (mlCharString &string1_, mlCharString &string2_); ///< comparison operator
      friend bool operator!= (mlCharString &string1_, mlCharString &string2_); ///< non-comparison

      void Assign(char* assignfrom); ///< assign from char
#ifndef NOSTL
      void Assign(std::string assignfrom); ///< assign from string
#endif

    private:

      bool Different(mlCharString &string1_, mlCharString &string2_); ///< are the mlCharStrings different?
      char* character_ptr_array_; ///< I think I may use this if mlArray REALLY screws up
      mlArray<char> character_dynarray_; ///< I would really rather use this instead, I'll try it using this, But I don't know how well it will work
    };

  }
}

#endif
