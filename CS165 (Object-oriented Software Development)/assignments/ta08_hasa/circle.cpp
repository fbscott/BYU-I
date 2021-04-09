#include <iostream>
#include "circle.h"

using namespace std;

/***********************************************************
 * Function: Circle :: display
 * Outputs a circle to the screen.
 ***********************************************************/
void Circle :: display() const
{
   center.display();

   cout << " - Radius: " << radius << endl;
}

/***********************************************************
 * Function: Circle :: promptForCircle
 * Prompts the user for the coordinates of the circle.
 ***********************************************************/
void Circle :: promptForCircle()
{
   center.promptForPoint();

   cout << "Enter radius: ";
   cin >> radius;
}

float Circle :: getX() const { return center.getX(); }
float Circle :: getY() const { return center.getY(); }
