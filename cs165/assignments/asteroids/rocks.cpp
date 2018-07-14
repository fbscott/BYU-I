/*****************************************************************************
 * Source File:
 *    Rock : The representation of a rock
 * Author:
 *    Scott Currell
 * Summary:
 *    Rock class. Children will inherit from this class.
 ****************************************************************************/

#include "rocks.h"

/*****************************************************************************
 * ROCK CONSTRUCTOR
 ****************************************************************************/
Rock :: Rock()
{
    setAlive(true);
    setRockID(0);
}

/*****************************************************************************
 * KILL ROCK
 ****************************************************************************/
// void Rock :: kill()
// {
//    setAlive(false);
// }

/*****************************************************************************
 * BIG ROCK CONSTRUCTOR
 ****************************************************************************/
BigRock :: BigRock()
{
   int rand = random(1,3);
   int dx = 0;
   int dy = 0;
   int x = 0;
   int y = 0;

   if (rand == 2)
   {
      x = -200;
      dx = 1;
      y = random( -200, 200);
      dy = 1;
   }
   else
   {
      x = 200;
      dx = -1;
      y = random( -200, 200);
      dy = -1;
   }

   if (y >= 0)
   {
      Velocity velocity(dx,-dy);
      setVelocity(velocity);
   }

   if (y < 0)
   {
      Velocity velocity(dx,dy);
      setVelocity(velocity);
   }

   Point point(x,y);
   setPoint(point);
   setAlive(true);
   setRockID(1);
   setRadius(17);
   rotation = 2;
}

/******************************************************************
 * BIG ROCK - DRAW
 *****************************************************************/
void BigRock :: draw()
{
    drawLargeAsteroid(point, rotation);

    for (int i = 0; i < 2; i++)
    ++rotation;
}

/******************************************************************
 * BIG ROCK - HIT
 ******************************************************************/
void BigRock :: hit()
{
    kill();
}

/******************************************************************
 * MEDIUM ROCK - CONSTRUCTOR
 ******************************************************************/
MediumRock :: MediumRock(Point bPoint, int mRock)
{

    int dx = 2;
    int dy = 2;
    
    if (mRock == 2)
    {
        dx = -2;
        dy = -2;
    }
    
    Velocity velocity(dx,dy);
    setVelocity(velocity);
    
    Point point(bPoint.getX(),bPoint.getY());
    setPoint(point);
    
    setAlive(true);
    setRockID(2);
    setRadius(9);
    rotation = 0;

}

/******************************************************************
 * MEDIUM ROCK - DRAW
 ******************************************************************/
void MediumRock :: draw()
{
    drawMediumAsteroid(point, rotation);
    
    for (int i = 0; i < 5; i++)
        ++rotation;
    
}

/******************************************************************
 * MEDIUM ROCK - HIT
 ******************************************************************/
void MediumRock :: hit()
{
    kill();
}

/******************************************************************
 * SMALL ROCK - CONSTRUCTOR
 ******************************************************************/
SmallRock :: SmallRock(Point sPoint, int sRock)
{
    
    int dx = 3;
    int dy = 3;
    
    if (sRock == 2)
    {
        dx = -3;
        dy = -3;
    }

    Velocity velocity(dx,dy);
    setVelocity(velocity);
    
    Point point(sPoint.getX(),sPoint.getY());
    setPoint(point);
    
    setAlive(true);
    setRockID(3);
    setRadius(5);
    rotation = 0;
    
}

/******************************************************************
 * SMALL ROCK - DRAW
 ******************************************************************/
void SmallRock :: draw()
{
    drawSmallAsteroid(point, rotation);
    
    for (int i = 0; i < 10; i++)
        rotation++;
}

/******************************************************************
 * SMALL ROCK - HIT
 ******************************************************************/
void SmallRock :: hit()
{
    kill();
}
