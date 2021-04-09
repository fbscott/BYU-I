/*****************************************************************************
 * Header File:
 *    FlyingObject : The representation of a flying object
 * Author:
 *    Scott Currell
 * Summary:
 *    Base flying object class. Children (bird/bullet) will inherit from this
 *    class.
 ****************************************************************************/

#ifndef FLYINGOBJECT_H
#define FLYINGOBJECT_H

#include "point.h"
#include "velocity.h"
#include "uiDraw.h"

/*****************************************************************************
 * POINT
 * A single position.  
 ****************************************************************************/
class FlyingObject : public Point, public Velocity
{
   private:
      Point point;       // base object point
      Velocity velocity; // base object velocity
      bool alive;        // base state: alive/dead

   public:
      // getters
      Point getPoint()        const { return point; }
      Velocity getVelocity()  const { return velocity; }
      bool isAlive()          const { return alive; }

      // setters
      void setPoint(Point);
      void setVelocity(Velocity);
      void setAlive(bool);

      // methods
      virtual void draw();
      virtual void advance();
      virtual void kill();
};

#endif // FLYINGOBJECT_H
