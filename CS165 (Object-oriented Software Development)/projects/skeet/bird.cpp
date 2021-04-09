/*****************************************************************************
 * Source File:
 *    Bird : The representation of a bird
 * Author:
 *    Scott Currell
 * Summary:
 *    Child of FlyingObject class. Children (standard/tough/sacred) will
 *    inherit from this class.
 ****************************************************************************/

#include "bird.h"
#include <cassert>

/*****************************************************************************
 * BIRD - default constructor
 ****************************************************************************/
Bird :: Bird()
{
   int dx = random(1, 5);
   int dy = random(3, 5);
   int x = -200;
   int y = random(-200, 200);

   if (y >= 0)
   {
      Velocity velocity(dx, -dy);
      setVelocity(velocity);
   }

   if (y < 0)
   {
      Velocity velocity(dx, dy);
      setVelocity(velocity);
   }

   Point point(x, y);
   setPoint(point);
   setAlive(true);
}

/*****************************************************************************
 * DRAW - draws the standard bird
 ****************************************************************************/
void Bird :: draw()
{
    drawCircle(getPoint(), 15);
}

int Bird :: hit()
{
    kill();
    return 1;
}
