#ifndef POINT_H
#define POINT_H

class Point
{
private:
   int x;
   int y;

public:
   void display() const;
   int getX() const;
   int getY() const;
   void setX(int);
   void setY(int);
};

#endif
