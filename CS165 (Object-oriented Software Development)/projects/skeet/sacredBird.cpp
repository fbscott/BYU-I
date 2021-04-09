/*****************************************************************************
 * Source File:
 *    SacredBird : The representation of a bird
 * Author:
 *    Scott Currell
 * Summary:
 *    Child of bird class.
 ****************************************************************************/

#include "sacredBird.h"
#include <cassert>


/*****************************************************************************
 * SACRED BIRD
  ****************************************************************************/
SacredBird :: SacredBird()
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
 * DRAW
 ****************************************************************************/
void SacredBird :: draw()
{
   drawSacredBird(getPoint(), 15);
}


/*****************************************************************************
 * HIT
 ****************************************************************************/
int SacredBird :: hit()
{
   kill();
   return -10;
}
