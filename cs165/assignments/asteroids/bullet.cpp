/*****************************************************************************
 * Source File:
 *    Bullet : The representation of a bullet
 * Author:
 *    Scott Currell
 * Summary:
 *    Draw and move the bullet.
 ****************************************************************************/

#include "bullet.h"
#include <cmath>

/*********************************
 * BULLET
 *********************************/
Bullet :: Bullet()
{
   setAlive(true);
}

/*********************************
 * KILL
 *********************************/
void Bullet :: kill()
{
   setAlive(false);
   frames = 0; // bullet lifespan
}

/*********************************
 * DRAW
 *********************************/
void Bullet :: draw()
{
   drawDot(getPoint());

   if (frames == (BULLET_LIFE - 1))
   {
      kill();
   }

   frames++;
}

/*********************************
 * FIRE
 *********************************/
void Bullet :: fire(Point shipPoint, float shipAngle, Velocity shipVelocity)
{
   Velocity velocity;

   // set point to that of the ship
   setPoint(shipPoint);

   // add ship's position, angle, and velocity to those of the bullet
   velocity.setDx(shipVelocity.getDx() + cos((float)(90 + shipAngle) * M_PI/180) * BULLET_SPEED);
   velocity.setDy(shipVelocity.getDy() + sin((float)(90 + shipAngle) * M_PI/180) * BULLET_SPEED);

   setVelocity(velocity);
}
