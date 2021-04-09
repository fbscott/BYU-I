/*****************************************************************************
 * Source File:
 *    FlyingObject : The representation of a flying object
 * Author:
 *    Scott Currell
 * Summary:
 *    Base flying object class. Children (bird/bullet) will inherit from this
 *    class.
 ****************************************************************************/

#include "flyingObject.h"
#include <cassert>

/*****************************************************************************
 * KILL OBJECT
 ****************************************************************************/
void FlyingObject :: advance(int screenSize)
{
   point.addX(velocity.getDx());
   point.addY(velocity.getDy());

   // wrap asteroids when they go off screen
   if (point.getX() > screenSize / 2)
   {
      point.addX(-screenSize);
   }

   if (point.getX() < -screenSize / 2)
   {
      point.addX(screenSize);
   }

   if (point.getY() > screenSize / 2)
   {
      point.addY(-screenSize);
   }

   if (point.getY() < -screenSize / 2)
   {
      point.addY(screenSize);
   }
}

/*****************************************************************************
 * KILL OBJECT
 ****************************************************************************/
void FlyingObject :: kill()
{ 
   alive = false;
}
