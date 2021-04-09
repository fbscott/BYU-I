/*****************************************************************************
 * Source File:
 *    ToughBird : The representation of a bird
 * Author:
 *    Scott Currell
 * Summary:
 *    Child of bird class.
 ****************************************************************************/

#include "toughBird.h"
#include <cassert>

/*****************************************************************************
 * TOUGH BIRD
 * Gets three hits
 ****************************************************************************/
ToughBird :: ToughBird()
{
   int dx = random(1, 3);
   int dy = random(1, 2);
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
   hits = 3;
}

/*****************************************************************************
 * DRAW
 * Draw the tough bird
 ****************************************************************************/
void ToughBird :: draw()
{
   drawToughBird(getPoint(), 15, hits);
}

/*****************************************************************************
 * HIT
 * Incriment score for each hit (+3 on final hit). Kill bird after 3 hits.
 ****************************************************************************/
int ToughBird :: hit()
{
   hits--;

   if(!hits)
   {
      kill();
      return 3;
   }
   else
   {
      return 1;
   }

   return 0;
}
