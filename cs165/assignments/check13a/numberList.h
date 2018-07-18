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

   int getNumber(int index) const;
   void setNumber(int index, int value);
   
   void displayList() const;

};

#endif
