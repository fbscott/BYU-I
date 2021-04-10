/*****************************************************************************
 * Header File:
 *    FlyingObject : The representation of a flying object
 * Author:
 *    [student name obfuscated]
 * Summary:
 *    Base flying object class. Children (bird/bullet) will inherit from this
 *    class.
 ****************************************************************************/

#ifndef flyingObject_h
#define flyingObject_h

#include "point.h"
#include "velocity.h"

/*****************************************************************************
 * POINT
 * A single position.  
 ****************************************************************************/
class FlyingObject
{
   protected:
      // base objects
      Point point; 
      Velocity velocity;
      bool alive;

   public:
      // getters
      Point getPoint()        const { return point;    }
      Velocity getVelocity()  const { return velocity; }
      bool isAlive()                { return alive;    }

      // setters
      void setPoint(Point point)          { this -> point    = point;    }
      void setVelocity(Velocity velocity) { this -> velocity = velocity; }
      void setAlive(bool alive)           { this -> alive    = alive;    }

      // pure virtual functions
      virtual void draw() =0;
      // virtual void hit() =0;

      // methods
      void advance(int);
      virtual void kill();
};

#endif // flyingObject_h
