/*****************************************************************************
 * Header File:
 *    Ship : The representation of a ship
 * Author:
 *    Scott Currell
 * Summary:
 *    Draw and move the ship.
 ****************************************************************************/

#ifndef ship_h
#define ship_h

#define SHIP_SIZE 10
#define SHIP_SPIN 6
#define SHIP_THRUST 0.5

#include "flyingObject.h"
#include "uiDraw.h"
#include "uiInteract.h"
#include <cmath>

class Ship : public FlyingObject
{
   private:
      float angle;

   public:
      Ship();

      float getAngle()       const { return angle;    }
      Point getPoint()       const { return point;    }
      Velocity getVelocity() const { return velocity; }

      void draw();
      void kill();

      void thrustLeft();
      void thrustRight();
      void thrustBottom();
      bool thrust;
};

#endif /* ship_h */
