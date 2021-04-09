/*****************************************************************************
 * Header File:
 *    SacredBird : The representation of a bird
 * Author:
 *    Scott Currell
 * Summary:
 *    Child of bird class.
 ****************************************************************************/


#ifndef SACREDBIRD_H
#define SACREDBIRD_H

#include "bird.h"

/*****************************************************************************
 * SACRED BIRD
 ****************************************************************************/
class SacredBird : public Bird
{
   private:
      int hits;
      Point point;
      Velocity velocity;

   public:
      SacredBird();
      SacredBird(Point);

      virtual void draw();
      virtual int hit();
};

#endif // SACREDBIRD_H
