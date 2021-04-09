/*********************************************************************
 * File: game.cpp
 * Description: Contains the implementaiton of the game class
 *  methods.
 *********************************************************************/

#include "game.h"
#include "uiDraw.h"
#include "uiInteract.h"

// These are needed for the getClosestDistance function...
#include <limits>
#include <algorithm>

#define OFF_SCREEN_BORDER_AMOUNT 5
#define SCREEN_SIZE 400

using namespace std;

/**************************************************************************
 * GAME CONSTRUCTOR
 **************************************************************************/
Game :: Game(Point topLeft, Point bottomRight)
{
   ship = NULL;
   createBigRock();
}

/**************************************************************************
 * GAME :: ADVANCE
 **************************************************************************/
void Game :: advance()
{
   advanceRocks();
   advanceShip();
   advanceBullets();
   handleCollisions();
   cleanUpZombies();
}

/**************************************************************************
 * GAME :: ADVANCE ROCKS
 **************************************************************************/
void Game :: advanceRocks()
{
   vector<Rock*> :: iterator it;

   for (it = rocks.begin(); it < rocks.end(); ++it)
   {
      if ((*it) -> isAlive()) {
         (*it) -> advance(SCREEN_SIZE);
      }
   }
}

/**************************************************************************
 * GAME :: CREATE BIG ROCK
 **************************************************************************/
// Rock* Game :: createBigRock()
void Game :: createBigRock()
{
   for (int i = 0; i < 5; i++)
   {
      rocks.push_back(new BigRock);
   }
}

/**************************************************************************
 * GAME :: CREATE MEDIUM ROCK
 **************************************************************************/
void Game :: createMediumRock(Point bPoint, int mRock)
{
   rocks.push_back(new MediumRock(bPoint, mRock));
}

/**************************************************************************
 * GAME :: CREATE SMALL ROCK
 **************************************************************************/
void Game :: createSmallRock(Point bPoint, int sRock)
{
   rocks.push_back(new SmallRock(bPoint, sRock));
}

/**************************************************************************
 * GAME :: ADVANCE SHIP
 **************************************************************************/
void Game :: advanceShip()
{
   // if no ship exists
   if (ship == NULL)
   {
      ship = new Ship;
   }
   // move the ship
   else
   {
      ship -> advance(SCREEN_SIZE);
   }
}

/**************************************************************************
 * GAME :: ADVANCE BULLETS
 **************************************************************************/
void Game :: advanceBullets()
{
   vector<Bullet*> :: iterator bit;

   for (bit = bullets.begin(); bit < bullets.end(); ++bit)
   {
   if ((*bit) -> isAlive())
      (*bit) -> advance(SCREEN_SIZE);
   }
}

/**************************************************************************
 * GAME :: IS ON SCREEN
 **************************************************************************/
bool Game :: isOnScreen(const Point & point)
{
   return (point.getX() >= topLeft.getX()     - OFF_SCREEN_BORDER_AMOUNT
        && point.getX() <= bottomRight.getX() + OFF_SCREEN_BORDER_AMOUNT
        && point.getY() >= bottomRight.getY() - OFF_SCREEN_BORDER_AMOUNT
        && point.getY() <= topLeft.getY()     + OFF_SCREEN_BORDER_AMOUNT);
}

/**************************************************************************
 * GAME :: HANDLE COLLISIONS
 **************************************************************************/
void Game :: handleCollisions()
{
    
   vector<Rock*> :: iterator rit;

   for (rit = rocks.begin(); rit != rocks.end(); rit++)
   {
      if (ship -> isAlive() && getClosestDistance(*ship, (**rit)) < (*rit) -> getRadius())
      {
         ship -> kill();
         (*rit) -> hit();
      }
   }
    
   vector<Bullet*> :: iterator bit;

   for (bit = bullets.begin(); bit != bullets.end(); bit++)
   {
      vector<Rock*> :: iterator rit = rocks.begin();
      for (rit = rocks.begin(); rit != rocks.end(); rit++)
      {
         if ((*bit) -> isAlive() && getClosestDistance((**bit), (**rit)) < (*rit) -> getRadius())
         {
            (*rit) -> hit();

            //create two medium rocks and a small rock
            if ((*rit) -> getRockID() == 1)
            {
               createMediumRock((*rit) -> getPoint(), 1);
               createMediumRock((*rit) -> getPoint(), 2);
               createSmallRock((*rit) -> getPoint(), 1);
            }

            //create a small rock
            if ((*rit) -> getRockID() == 2)
            {
               createSmallRock((*rit) -> getPoint(), 1);
               createSmallRock((*rit) -> getPoint(), 2);
            }

            // the bullet is dead as well
            (*bit) -> kill();
            break;
         }
      }
   }
}

/**************************************************************************
 * GAME :: CLEAN UP ZOMBIES
 **************************************************************************/
void Game :: cleanUpZombies()
{
    
   vector<Rock*> :: iterator rit;

   for (rit = rocks.begin(); rit != rocks.end();)
   {
      if ((*rit) -> isAlive() == false)
      {
         delete *rit;
         *rit = NULL;
         rit = rocks.erase(rit);
      }
      else rit++;
   }

   if (ship != NULL && !ship -> isAlive())
   {
      delete ship;
   }

    vector<Bullet*> :: iterator bit;

    for (bit = bullets.begin(); bit != bullets.end();)
    {
      if ((*bit) -> isAlive() == false)
      {
         delete *bit;
         *bit = NULL;
         bit = bullets.erase(bit);
      }
      else bit++;
    }
}

/**************************************************************************
 * GAME :: HANDLE INPUT
 **************************************************************************/
void Game :: handleInput(const Interface & ui)
{
   if (ui.isLeft())
   {
      ship -> thrustRight();
   }
   
   if (ui.isRight())
   {
      ship -> thrustLeft();
   }
   
   if (ui.isUp())
   {
      ship -> thrustBottom();
   }
   else
   {
      ship -> thrust = false;
   }

   if (ui.isSpace() && ship -> isAlive())
   {
      Bullet *newBullet = new Bullet;

      newBullet -> fire(ship -> getPoint(), ship -> getAngle(), ship -> getVelocity());

      bullets.push_back(newBullet);
   }
}

/**************************************************************************
 * GAME :: DRAW
 **************************************************************************/
void Game :: draw(const Interface & ui)
{
   vector<Rock*> :: iterator it;
   for (it = rocks.begin(); it < rocks.end(); ++it)
   {
      if ((*it) -> isAlive())
      {
         (*it) -> draw();
      }
   }

   if (ship != NULL && ship -> isAlive())
   {
      ship -> draw();
   }
    
   vector<Bullet*> :: iterator bit;
   for (bit = bullets.begin(); bit < bullets.end(); ++bit)
   {
   if ((*bit) -> isAlive())
      (*bit) -> draw();
   }
}

// You may find this function helpful...

/**************************************************************************
 * Function: getClosestDistance
 * Description: Determine how close these two objects will
 *   get in between the frames.
 **************************************************************************/
float Game :: getClosestDistance(const FlyingObject &obj1, const FlyingObject &obj2) const
{
   // find the maximum distance traveled
   float dMax = max(abs(obj1.getVelocity().getDx()), abs(obj1.getVelocity().getDy()));
   dMax = max(dMax, abs(obj2.getVelocity().getDx()));
   dMax = max(dMax, abs(obj2.getVelocity().getDy()));
   dMax = max(dMax, 0.1f); // when dx and dy are 0.0. Go through the loop once.
   
   float distMin = std::numeric_limits<float>::max();
   for (float i = 0.0; i <= dMax; i++)
   {
      Point point1(obj1.getPoint().getX() + (obj1.getVelocity().getDx() * i / dMax),
                     obj1.getPoint().getY() + (obj1.getVelocity().getDy() * i / dMax));
      Point point2(obj2.getPoint().getX() + (obj2.getVelocity().getDx() * i / dMax),
                     obj2.getPoint().getY() + (obj2.getVelocity().getDy() * i / dMax));
      
      float xDiff = point1.getX() - point2.getX();
      float yDiff = point1.getY() - point2.getY();
      
      float distSquared = (xDiff * xDiff) +(yDiff * yDiff);
      
      distMin = min(distMin, distSquared);
   }
   
   return sqrt(distMin);
}
