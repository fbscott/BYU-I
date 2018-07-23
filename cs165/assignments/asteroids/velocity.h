/***********************************************************************
 * Header File:
 *    VELOCITY : A representation of the flying object's velocity
 * Author:
 *    Scott Currell
 * Summary:
 *    Everything wee need to know about the flying object's velocity: how fast
 *    it's moving in along the X and Y axes.
 ************************************************************************/

#ifndef velocity_h
#define velocity_h

// #include "point.h"

/*********************************************
 * VELOCITY
 * A single position.  
 *********************************************/
class Velocity
{
   private:
      float xVelocity;
      float yVelocity;

   public:
      // constructors
      Velocity();
      Velocity(float, float);

      // getters
      float getDx() const;
      float getDy() const;

      // setters
      void setDx(float);
      void setDy(float);
};

#endif // velocity_h
