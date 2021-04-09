#include "robot.h"
#include <iostream>
using namespace std;

/************************************
 * Function: Display
 * Purpose: Displays the robot.
 ************************************/
void Robot :: display() const
{
   position.display();
   cout << " - Energy: " << getEnergy();
}

void Robot :: setPosition(Point p)
{
   this->position = p;
}
void Robot :: setEnergy(int energy)
{
   if (energy < 0)
   {
      this->energy = 0;
   }
   else
   {
      this->energy = energy;
   }
}
int Robot :: getEnergy() const
{
   return this->energy;
}
