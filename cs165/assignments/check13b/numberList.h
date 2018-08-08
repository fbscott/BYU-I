/*******************
 * NumberList class
 *******************/
#ifndef NUMBER_LIST_H
#define NUMBER_LIST_H

#include <iostream>

class NumberList
{
private:
   int size;
   int *array;

public:
   NumberList()
   {
      size = 0;
      array = NULL;
   }

   // TODO: Add your constructor and destructor

   // implement a non-default constructor that accepts an integer for
   // the size of the number list
   NumberList(int reSize)
   {
      // dynamically allocate an array of size "reSize"
      array = new int[reSize];
      // save the size to the member var "size"
      size = reSize;
      // fill in a default value of 0 for each spot in the array
      for(int i = 0; i < reSize; i++)
      {
         array[i] = 0;
      }
   }

   // implement a destructor that frees up the memory of the array
   ~NumberList()
   {
      // delete the dynamically allocated array
      delete [] array;
      // set the array pointer to be NULL
      array = NULL;
      // output a message that says, "Freeing memory."
      std::cout << "Freeing memory\n";
   }

   // implement a copy constructor for the NumberList
   NumberList(const NumberList & rhs)
   {
      // array = NULL;
      // set the size of the new list to be the same as the other one
      size = rhs.size;
      // dynamically allocate an array of that size
      array = new int[size];
      // copy each value from the original NumberList array
      for (int i = 0; i < size; ++i)
      {
         array[i] = rhs.array[i];
      }
   }

   // implement an assignment operator
   NumberList operator = (const NumberList & rhs)
   {
      // see if the array is already allocated, if so, delete it
      if (array != NULL)
      {
         delete [] array;
         array = NULL;
      }
      // do the same things as the copy constructor (lines 53 - 61)
      size = rhs.size;
      array = new int[size];
      for (int i = 0; i < size; ++i)
      {
         array[i] = rhs.array[i];
      }
      // return a reference to the current object
      return * this;
   }

   int getNumber(int index) const;
   void setNumber(int index, int value);
   
   void displayList() const;

};

#endif
