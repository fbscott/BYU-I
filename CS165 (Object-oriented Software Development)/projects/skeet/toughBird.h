/*****************************************************************************
 * Header File:
 *    ToughBird : The representation of a bird
 * Author:
 *    Scott Currell
 * Summary:
 *    Child of bird class.
 ****************************************************************************/


#ifndef TOUGHBIRD_H
#define TOUGHBIRD_H

#include "bird.h"

/*****************************************************************************
 * TOUGH BIRD
 ****************************************************************************/
class ToughBird : public Bird
{
   private:
      int hits;
      Point point;
      Velocity velocity;

   public:
      ToughBird();
      ToughBird(Point);

      virtual void draw();
      virtual int hit();
};

#endif // TOUGHBIRD_H
