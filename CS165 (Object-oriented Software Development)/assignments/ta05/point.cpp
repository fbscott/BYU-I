#include "point.h"

#include <iostream>
using namespace std;

/******************************************
 * Function: display
 * Purpose: Displays the point
 ******************************************/
void Point :: display() const
{
   // Note: We could just use x and y here and not the getters
   // because it's a member function. But this will force you
   // to deal with const :-)...

   cout << "(" << getX() << ", " << getY() << ")";
}

int Point :: getX() const
{
   return x;
}

int Point :: getY() const
{
   return y;
}

void Point :: setX(int x)
{
   if (x < 1)
   {
      this->x = 1;
   } else if (x > 10)
   {
      this->x = 10;
   } else
   {
      this->x = x;
   }
}

void Point :: setY(int y)
{
   if (y < 1)
   {
      this->y = 1;
   } else if (y > 10)
   {
      this->y = 10;
   } else
   {
      this->y = y;
   }
}
