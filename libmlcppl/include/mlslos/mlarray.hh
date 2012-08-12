#ifndef ML_ARRAY_HH
#define ML_ARRAY_HH

#include "mlslos/mlobject.hh"
#include "mlslos/mlcollection.hh"

namespace ml
{
  /** Library Of Stuff */
  namespace los
  {

#warning Not safe for use yet

    /** @todo implement errors when something goes wrong
     *  @warning is currently only partially safe to use */

    /** This class should not be directly used!
     *  @warning It has no checking or safety features, other classes will implement that */
    template <typename Tp> class mlArray : mlCollection
    {
    public:
      typedef Tp* PtrType; ///< pointer type
      typedef Tp& RefType; ///< Reference type
      typedef Tp Type; ///< Type

      mlArray();
      /** returns the Type at position pos, uses GetAt */
      Type operator[](mlsize_type pos);

      /** returns the Type at position pos */
      Type GetAt(mlsize_type pos);

      /** Returns the current size of the array */
      mlsize_type Size() const;

      /** resize the array */
      void ReSize(mlsize_type size);

      /** Add a Type at the specified position, and then recreate the array */
      void AddAt(Tp toadd, mlsize_type pos);

      /** Del(ete) a Type at the specified position, and then recreate the array */
      void DelAt(mlsize_type pos);

      /** Set the variable at pos with toset */
      void SetAt(Tp toset, mlsize_type pos);

    private:
      PtrType* Tp_pointer_array_; ///< will always contain the list of pointers
      mlsize_type size_; ///< current size of array

      /** Creates a new pointer_array for Tp_pointer_array by adding the selected Type
       *  At the position indicated by pos */
      PtrType* AddType(Tp toadd, mlsize_type pos);

      /** same as above, except it removes it from the array instead */
      PtrType* RemType(mlsize_type pos);

      /** same as the other two, except it modifies in place */
      PtrType* SetType(Tp toset, mlsize_type pos);

      /** return a PtrType* of the wanted size */
      PtrType* GetArrayOfSize(mlsize_type size);
    };

    // Beginning of all the implementations

    template<typename Tp> void mlArray<Tp>::SetAt(Tp toset, mlsize_type pos)
    {
      PtrType* temp_array = this->SetType(toset, pos);
      delete(this->Tp_pointer_array_);
      this->Tp_pointer_array_ = temp_array;
    }

    template<typename Tp> Tp** mlArray<Tp>::SetType(Tp toset, mlsize_type pos)
    {
      PtrType* temp_array = this->GetArrayOfSize(this->size_);
      bool finished = false;
      mlsize_type currentposition = 0;
      while(finished == false)
        {
          if (currentposition != pos && currentposition < this->size_)
            {
              temp_array[currentposition] = new Tp;
              *temp_array[currentposition] = *(this->Tp_pointer_array_[currentposition]);
              currentposition++;
            }
          else if (currentposition == pos && currentposition < this->size_)
            {
              temp_array[currentposition] = new Tp;
              *temp_array[currentposition] = toset;
              currentposition++;
            }
          else if (currentposition == this->size_)
            {
              finished = true;
            }
        }
      return temp_array;
    }

    template<typename Tp> Tp mlArray<Tp>::GetAt(mlsize_type pos)
    {
      return *(Tp_pointer_array_[pos]);
    }

    template<typename Tp> Tp mlArray<Tp>::operator [](mlsize_type pos)
    {
      return this->GetAt(pos);
    }

    template<typename Tp> mlsize_type mlArray<Tp>::Size() const
    {
      return this->size_;
    }

    template<typename Tp> void mlArray<Tp>::ReSize(mlsize_type size)
    {
      this->size_ = size;
    }

    template<typename Tp> mlArray<Tp>::mlArray()
    {
      this->Tp_pointer_array_ = new PtrType;
      this->size_ = 0;
    }

    template<typename Tp> void mlArray<Tp>::AddAt(Tp toadd, mlsize_type pos)
    {
      PtrType* temp_array = this->AddType(toadd, pos);
      delete(this->Tp_pointer_array_);
      this->Tp_pointer_array_ = temp_array;
      this->size_++;
    }

    template<typename Tp> void mlArray<Tp>::DelAt(mlsize_type pos)
    {
      PtrType* temp_array = this->RemType(pos);
      delete(this->Tp_pointer_array_);
      this->Tp_pointer_array_ = temp_array;
      this->size_--;
    }

    template<typename Tp> Tp** mlArray<Tp>::GetArrayOfSize(mlsize_type size)
    {
      PtrType* temp_array = new PtrType[size];

      return temp_array;
    }

    template<typename Tp> Tp** mlArray<Tp>::RemType(mlsize_type pos)
    {
      mlsize_type newsize = size_ - 1;
      PtrType* temp_array = this->GetArrayOfSize(newsize);

      bool removed = false;
      bool finished = false;
      mlsize_type currentposition = 0;

      while (removed == false || finished == false)
        {
          if (currentposition != pos && currentposition < newsize && removed == false)
            {
              temp_array[currentposition] = new Type;
              *temp_array[currentposition] = *(this->Tp_pointer_array_[currentposition]);
              currentposition++;
            }
          else if (currentposition == pos && removed == false && currentposition < newsize)
            {
              removed = true;
            }
          else if (currentposition == pos && removed == true && currentposition < newsize)
            {
              temp_array[currentposition] = new Type;
              *temp_array[currentposition] = *(this->Tp_pointer_array_[currentposition+1]);
              currentposition++;
            }
          else if (currentposition == newsize)
            {
              finished = true;
            }
        }
      return temp_array;
    }


    template<typename Tp> Tp** mlArray<Tp>::AddType(Tp toadd, mlsize_type pos)
    {
      mlsize_type newsize = size_ + 1;
      PtrType* temp_array = this->GetArrayOfSize(newsize);

      bool added = false;
      bool finished = false;
      mlsize_type currentposition = 0;
      while(added == false || finished == false)
        {
          if (currentposition != pos && currentposition < newsize && added == false)
            {
              temp_array[currentposition] = new Type;
              *temp_array[currentposition] = *(this->Tp_pointer_array_[currentposition]);
              currentposition++;
            }
          else if (currentposition != pos && added == true && currentposition < newsize)
            {
              temp_array[currentposition] = new Type;
              *temp_array[currentposition] = *(this->Tp_pointer_array_[currentposition - 1]);
              currentposition++;
            }
          else if (currentposition == pos && added == false && currentposition < newsize)
            {
              temp_array[currentposition] = new Type;
              *temp_array[currentposition] = toadd;
              currentposition++;
              added = true;
            }
          else if (currentposition == newsize)
            {
              finished = true;
            }
        }
      return temp_array;
    }

  }
}

#endif
