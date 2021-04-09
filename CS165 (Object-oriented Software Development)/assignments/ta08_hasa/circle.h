#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include "point.h"

/***********************************************************
 * Class: Circle
 * Description: Holds an integer pair (xCoord, yCoord) as a center point and
 * a radius for a circle.
 ***********************************************************/
class Circle
{
   private:
      Point center;
      float radius;

   public:
      // Getters
      float getRadius() const { return radius; }
      float getX() const;
      float getY() const;

      // Setters
      void setRadius(float radius) { this -> radius = radius; }

      void promptForCircle();
      void display() const;
};

#endif
