/*****************************************************************************
 * Header File:
 *    Bullet : The representation of a bullet
 * Author:
 *    [student name obfuscated]
 * Summary:
 *    Draw and move the bullet.
 ****************************************************************************/

#ifndef bullet_h
#define bullet_h

#define BULLET_SPEED 5
#define BULLET_LIFE 40

#include "flyingObject.h"
#include "uiDraw.h"
#include "ship.h"
#include <stdio.h>

/*************************************************
 * BULLET
 *************************************************/
class Bullet : public FlyingObject
{
   public:
      Bullet();
      void kill();
      void draw();
      // get ship's position, angle, and velocity
      void fire(Point, float, Velocity);
      int frames;
};

#endif /* bullet_h */
