/***********************************************************************
 * Header File:
 *    Lander : The representation of a position on the screen
 * Author:
 *    Scott Currell
 * Summary:
 *    Everything we need to know about a location on the screen, including
 *    the location and the bounds.
 ************************************************************************/

#ifndef LANDER_H
#define LANDER_H

// #include "point.h"
#include "uiDraw.h"
#include "velocity.h"
// #include "uiInteract.h"

/*********************************************
 * LANDER
 * A single position.  
 *********************************************/
class Lander
{
private:
   Point landerPoint;
   Velocity landerVelocity;
   bool alive;
   bool landed;
   // bool thrust;
   int fuel;

public:
   // constructors
   Lander()
   {
      // setdY(1.2);
      // setdX(5.2);
      alive = true;
      landed = false;
      // bool thrust = true;
      fuel = 500;
   }
   // Lander();

   // getters
   Point getPoint() const { return landerPoint; }
   // Velocity getVelocity() const { return Velocity; }
   Velocity getVelocity() const { return landerVelocity; }
   int getFuel() const { return fuel; }

   // setters
   void setLanded(bool);
   void setAlive(bool);
   void setFuel(int);

   // methods
   bool isAlive();
   bool isLanded();
   bool canThrust();
   
   void applyGravity(float);
   void applyThrustLeft();
   void applyThrustRight();
   void applyThrustBottom();

   void advance();
   void draw();
};

#endif // LANDER_H