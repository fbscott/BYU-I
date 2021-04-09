/***********************************************************************
 * Implementation File:
 *    VELOCITY : A class representing the lander's velocity
 * Author:
 *    Scott Currell
 * Summary:
 *    Set lander physics: left, right, and up directions and velocities. 
 ************************************************************************/

#include "velocity.h"
// using namespace std;

/********************************************
 * VELOCITY :: CONSTRUCTOR
 ********************************************/
   Velocity :: Velocity()
   {
      setDx(0.0);
      setDy(0.0);
   }

   Velocity :: Velocity(float xVelocity, float yVelocity)
   {
      setDx(xVelocity);
      setDy(yVelocity);
   }

   // getters
   /**
    * GET X DIRECTION
    */
   float Velocity :: getDx() const { return xVelocity; }
   /**
    * GET Y DIRECTION
    */
   float Velocity :: getDy() const { return yVelocity; }

   // setters
   /**
    * SET X DIRECTION
    */
   void Velocity :: setDx(float xVelocity)
   {
      this -> xVelocity = xVelocity;
   }

   /**
    * SET Y DIRECTION
    */
   void Velocity :: setDy(float yVelocity)
   {
      this -> yVelocity = yVelocity;
   }
