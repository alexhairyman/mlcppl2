#ifndef ML_COLLECTION_HH_
#define ML_COLLECTION_HH_
#include "mlobject.hh"

namespace ml
{
  namespace los
  {
    /** had to put it in this scope for now */
    typedef unsigned int mlsize_type;

    class mlCollection : mlObject
    {
    public:
      mlsize_type Size() const;
    };

  }
}

#endif
