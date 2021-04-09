/***********************************************************************
 * Header File:
 *    VELOCITY : A representation of the lander's velocity
 * Author:
 *    Scott Currell
 * Summary:
 *    Everything wee need to know about the lander's velocity: how fast it's
 *    moving in along the X and Y axes.
 ************************************************************************/

#ifndef VELOCITY_H
#define VELOCITY_H

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

#endif // VELOCITY_H
