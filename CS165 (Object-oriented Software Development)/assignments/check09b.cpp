/***********************************************************************
* Program:
*    Checkpoint 09b, Pure Virtual Functions
*    Brother Walker, CS165
* Author:
*    Scott Currell
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// For this assignment, for simplicity, you may put all of your classes
// in this file.

class Shape
{
private:
   string name;

public:
   virtual ~Shape() { }
   string getName() const { return name; }
   void setName(string name) { this -> name = name; }
   
   // TODO: Define your pure virtual function here
   virtual float getArea() const { return 0; }
};

class Circle : public Shape
{
private:
   float radius;

public:
   ~Circle()
   {
      cout << "Cleaning up " << getName() << endl;
   }

   float getRadius() const { return radius; }
   void setRadius(float radius) { this -> radius = radius; }

   // TODO: Implement a constructor here
   Circle() { setName("Circle"); }
   // TODO: Redefine getArea() here
   virtual float getArea() const { return 3.14 * radius * radius; }
};

class Rectangle : public Shape
{
private:
   float length;
   float width;

public:
   ~Rectangle()
   {
      cout << "Cleaning up " << getName() << endl;
   }

   float getLength() const { return length; }
   float getWidth() const { return width; }
   void setLength(float length) { this -> length = length; }
   void setWidth(float width) {this -> width = width; }

   // TODO: Implement a constructor here
   Rectangle() { setName("Rectangle"); }
   // TODO: Redefine getArea() here
   virtual float getArea() const { return length * width; }
};

const int MAX_SIZE = 10;

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   // We will put all of our code in main for this one, just to keep
   // the focus on the virtual functions and not on passing items
   // between functions.
   
   // TODO: 1. Declare your array here
   // For this assignment you can use the size: MAX_SIZE
   Shape * shape[MAX_SIZE];

   char letter;
   int count = 0;

   do
   {
      cout << "Please enter 'c' for circle, 'r' for rectangle or 'q' to quit: ";
      cin >> letter;

      if (letter == 'c')
      {
         float radius;
         cout << "Enter the radius: ";
         cin >> radius;

         // TODO: 2. Create your circle object here
         Circle * circle = new Circle;
         // set the radius value
         circle -> setRadius(radius);
         // add it to the array at index "count".
         shape[count] = circle;
         
         count++; // we have seen another shape
      }
      else if (letter == 'r')
      {
         float length;
         float width;

         cout << "Enter the length: ";
         cin >> length;

         cout << "Enter the width: ";
         cin >> width;
      
         // TODO: 3. Create your rectangle object here
         Rectangle * rectangle = new Rectangle;
         // set the length and width
         rectangle -> setLength(length);
         rectangle -> setWidth(width);
         // add it to the array at index "count".
         shape[count] = rectangle;

         count++; // we have seen another shape
      }

   } while (letter != 'q');

   // Set the precision for our decimals
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   // Now we will display each shape
   for (int i = 0; i < count; i++)
   {
      // TODO: 4. Add a cout statment here to display the name and the area
      // of each shape in the list in the format "Circle - 10.32"
      cout << shape[i] -> getName() << " - " << shape[i] -> getArea() << endl;

   }

   // TODO: 5. Loop through and free the memory of each object.
   for (int i = 0; i < count; i++)
   {
      delete shape[i];
   }

   return 0;
}
