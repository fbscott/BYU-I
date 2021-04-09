/***********************************************************************
 * Implementation File:
 *    LANDER : A class representing the lunar landscape
 * Author:
 *    Scott Currell
 * Summary:
 *    Apply physics to lander (move left, right, up), track fuel, and lander
 *    state (alive and can thrust)
 ************************************************************************/

#include "lander.h"
#include "game.h"

/********************************************
 * LANDER :: CONSTRUCTOR
 ********************************************/
   Lander :: Lander()
   {
      // set random location
      // found random function in uiDraw.cpp
      landerPoint.setX(random(-200, 200));
      landerPoint.setY(200); // TODO: set this to a const somewhere
      setAlive(true);
      setLanded(false);
      setThrust(true);
      setFuel(FUEL);
   }

   // setters
   /**
    * SET ALIVE
    */
   void Lander :: setAlive(bool alive)
   {
      this -> alive = alive;
   }

   /**
    * SET LANDED
    */
   void Lander :: setLanded(bool landed)
   {
      this -> landed = landed;
   }

   /**
    * SET THRUST
    */
   void Lander :: setThrust(bool thrust)
   {
      this -> thrust = thrust;
   }

   /**
    * SET FUEL
    */
   void Lander :: setFuel(int fuel)
   {
      this -> fuel = fuel;
   }

   // methods
   /**
    * IS ALIVE
    * Is the lander alive (not crashed)
    */
   bool Lander :: isAlive()
   {
      return alive;
   }

   /**
    * IS LANDED
    * Has the lander landed
    */
   bool Lander :: isLanded()
   {
      return landed;
   }

   /**
    * CAN THRUST
    * Allow thrust if fuel exists
    */
   bool Lander :: canThrust()
   {
      if (fuel < 1)
      {
         setThrust(false);
      }
      return thrust;
   }
   
   /**
    * APPLY GRAVITY
    * Increase vertical velocity
    */
   void Lander :: applyGravity(float gravity)
   {
      landerVelocity.setDy(landerVelocity.getDy() - gravity);
      landerPoint.addY(-1.0 * gravity);
   }

   /**
    * APPLY THRUST LEFT
    * Move lander left
    */
   void Lander :: applyThrustLeft()
   {
      if (thrust)
      {
         landerVelocity.setDx(landerVelocity.getDx() + 0.1);
         landerPoint.addX(0.1);
         fuel -= 1;
      }
   }

   /**
    * APPLY THRUST RIGHT
    * Move lander right
    */
   void Lander :: applyThrustRight()
   {
      if (thrust)
      {
         landerVelocity.setDx(landerVelocity.getDx() - 0.1);
         landerPoint.addX(0.1);
         fuel -= 1;
      }
   }

   /**
    * APPLY THRUST LEFT
    * Move lander up
    */
   void Lander :: applyThrustBottom()
   {
      if (thrust)
      {
         landerVelocity.setDy(landerVelocity.getDy() + 0.3);
         landerPoint.addY(0.3);
         fuel -= 3;
      }
   }

   /**
    * ADVANCE
    * Increase horizontal velocity
    */
   void Lander :: advance()
   {
      landerPoint.addY(landerVelocity.getDy());
      landerPoint.addX(landerVelocity.getDx());
   }

   /**
    * DRAW
    * Draw the lander at a provided point
    */
   void Lander :: draw()
   {
      drawLander(landerPoint);
   }
