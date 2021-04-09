/*****************************************************************************
 * Header File:
 *    Bullete : The representation of a bullet
 * Author:
 *    Scott Currell
 * Summary:
 *    Child of FlyingObject class.
 ****************************************************************************/

#ifndef BULLET_H
#define BULLET_H
#define BULLET_SPEED 10.0

#include "flyingObject.h"

/*****************************************************************************
 * BILLET
 ****************************************************************************/
class Bullet : public FlyingObject
{
   public:
      Bullet();
      void draw();
      void fire(Point, float);
};

#endif // BULLET_H
