/*****************************************************************************
 * Header File:
 *    Bird : The representation of a bird
 * Author:
 *    Scott Currell
 * Summary:
 *    Child of FlyingObject class. Children (standard/tough/sacred) will
 *    inherit from this class.
 ****************************************************************************/

#ifndef BIRD_H
#define BIRD_H

#include "flyingObject.h"

/*****************************************************************************
 * STANDARD BIRD
 ****************************************************************************/
class Bird : public FlyingObject
{
   private:
      Point point;
      Velocity velocity;


   public:
      Bird();
      Bird(Point);

      virtual void draw();
      virtual int hit();
};

#endif // BIRD_H
