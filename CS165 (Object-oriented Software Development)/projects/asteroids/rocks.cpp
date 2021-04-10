/*****************************************************************************
 * Source File:
 *    Rock : The representation of a rock
 * Author:
 *    [student name obfuscated]
 * Summary:
 *    Rock class. Children will inherit from this class.
 ****************************************************************************/

#define DISTENCE_FROM_CENTER 200

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
 * ROCK - KILL
 ****************************************************************************/
void Rock :: kill()
{
    setAlive(false);
}

/*****************************************************************************
 * BIG ROCK CONSTRUCTOR
 ****************************************************************************/
BigRock :: BigRock()
{
   int rand = random(1, 3);
   int x    = 0;
   int y    = 0;
   int dx   = 0;
   int dy   = 0;

   if (rand == 2)
   {
      x  = -DISTENCE_FROM_CENTER;
      y  = random( -DISTENCE_FROM_CENTER, DISTENCE_FROM_CENTER );
      dx = 1;
      dy = 1;
   }
   else
   {
      x  = DISTENCE_FROM_CENTER;
      y  = random( -DISTENCE_FROM_CENTER, DISTENCE_FROM_CENTER );
      dx = -1;
      dy = -1;
   }

   if (y >= 0)
   {
      Velocity velocity(dx, -dy);
      setVelocity(velocity);
   }

   if (y < 0)
   {
      Velocity velocity(dx, dy);
      setVelocity(velocity);
   }

   Point point(x, y);
   setPoint(point);
   setAlive(true);
   setRockID(1);
   setRadius(BIG_ROCK_SIZE);
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
MediumRock :: MediumRock(Point medPoint, int medRock)
{
   int dx = 2;
   int dy = 2;

   if (medRock == 2)
   {
      dx = -2;
      dy = -2;
   }

   Velocity velocity(dx, dy);
   setVelocity(velocity);

   Point point(medPoint.getX(), medPoint.getY());
   setPoint(point);

   setAlive(true);
   setRockID(2);
   setRadius(MEDIUM_ROCK_SIZE);
   rotation = 0;

}

/******************************************************************
 * MEDIUM ROCK - DRAW
 ******************************************************************/
void MediumRock :: draw()
{
   drawMediumAsteroid(point, rotation);

   for (int i = 0; i < 5; i++)
   {
     ++rotation;
   }
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
SmallRock :: SmallRock(Point smallPoint, int smallRock)
{
   int dx = 3;
   int dy = 3;

   if (smallRock == 2)
   {
      dx = -3;
      dy = -3;
   }

   Velocity velocity(dx, dy);
   setVelocity(velocity);

   Point point(smallPoint.getX(), smallPoint.getY());
   setPoint(point);

   setAlive(true);
   setRockID(3);
   setRadius(SMALL_ROCK_SIZE);
   rotation = 0;
}

/******************************************************************
 * SMALL ROCK - DRAW
 ******************************************************************/
void SmallRock :: draw()
{
   drawSmallAsteroid(point, rotation);

   for (int i = 0; i < 10; i++)
   {
      rotation++;
   }
}

/******************************************************************
 * SMALL ROCK - HIT
 ******************************************************************/
void SmallRock :: hit()
{
    kill();
}
