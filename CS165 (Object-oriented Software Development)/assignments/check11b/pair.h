/*****************************************************
 * File: pair.h
 * Author: Scott Currell
 *
 * Purpose: Defines a Pair template class that can hold
 *   two items of arbitrary data types.
 ******************************************************/

#ifndef PAIR_H
#define PAIR_H

// TODO: Fill in this class
// Put all of your method bodies right in this file
template <class T1, class T2>
class Pair
{
   public:
      // getters
      T1 getFirst()  const { return t1; }
      T2 getSecond() const { return t2; }
      // setters
      void setFirst(const T1 & t1)  { this -> t1 = t1; }
      void setSecond(const T2 & t2) { this -> t2 = t2; }
      // print to screen
      void display() {
         cout << t1 << " - " << t2;
      };
   private:
      T1 t1;
      T2 t2;
};

#endif // PAIR_H
