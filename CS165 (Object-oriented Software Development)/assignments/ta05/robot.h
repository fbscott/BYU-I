#ifndef ROBOT_H
#define ROBOT_H

#include "point.h"

class Robot
{
private:
   Point position;
   int energy;

public:
   void display() const;
   void setPosition(Point);
   void setEnergy(int);
   int getEnergy() const;
};

#endif
