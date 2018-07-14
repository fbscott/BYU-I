/*********************************************************************
 * File: game.cpp
 * Description: Contains the implementaiton of the game class
 *  methods.
 *
 *********************************************************************/

#include "game.h"

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"

#include <cassert>
#include <vector>

#define OFF_SCREEN_BORDER_AMOUNT 5
#define SCREEN_SIZE 400

// These are needed for the getClosestDistance function...
#include <limits>
#include <algorithm>
using namespace std;



/***************************************
 * GAME CONSTRUCTOR
 ***************************************/
Game :: Game(Point tl, Point br)
 // : topLeft(tl), bottomRight(br)
{
   createBigRock();
}

/****************************************
 * GAME DESTRUCTOR
 ****************************************/
// Game :: ~Game()
// {
//    // TODO: Check to see if there is currently a rock allocated
//    //       and if so, delete it.
//    if(rock != NULL)
//    {
//       delete rock;
//       rock = NULL;
//    }

// }

/***************************************
 * GAME :: ADVANCE
 * Advance the game one unit of time
 ***************************************/
void Game :: advance()
{
   // advanceBullets();
   advanceRocks();
   // handleCollisions();
   // cleanUpZombies();
}

/***************************************
 * GAME :: ADVANCE BULLETS
 * Go through each bullet and advance it.
 ***************************************/
// void Game :: advanceBullets()
// {
//    // Move each of the bullets forward if it is alive
//    for (int i = 0; i < bullets.size(); i++)
//    {
//       if (bullets[i].isAlive())
//       {
//          // this bullet is alive, so tell it to move forward
//          bullets[i].advance();
         
//          if (!isOnScreen(bullets[i].getPoint()))
//          {
//             // the bullet has left the screen
//             bullets[i].kill();
//          }
         
//       }
//    }
// }

/**************************************************************************
 * GAME :: ADVANCE ROCKS
 **************************************************************************/
void Game :: advanceRocks()
{
    vector<Rock*> :: iterator it;
    for (it = rocks.begin(); it < rocks.end(); ++it)
    {
        if ((*it) -> isAlive())
            (*it) -> advance(SCREEN_SIZE);
    }
}

/**********************************************************
 * GAME :: CREATE BIG ROCK
 **********************************************************/
// Rock* Game :: createBigRock()
void Game :: createBigRock()
{
    for (int i = 0; i < 5; i++)
    {
        rocks.push_back(new BigRock);
    }
}

/***********************************************************
 * GAME :: CREATE MEDIUM ROCK
 ***********************************************************/
void Game :: createMediumRock(Point bPoint, int mRock)
{
    rocks.push_back(new MediumRock(bPoint, mRock));
    
}

/***********************************************************
 * GAME :: CREATE SMALL ROCK
 ***********************************************************/
void Game :: createSmallRock(Point bPoint, int sRock)
{
    rocks.push_back(new SmallRock(bPoint, sRock));
}

/**************************************************************************
 * GAME :: IS ON SCREEN
 * Determines if a given point is on the screen.
 **************************************************************************/
bool Game :: isOnScreen(const Point & point)
{
   return (point.getX() >= topLeft.getX() - OFF_SCREEN_BORDER_AMOUNT
      && point.getX() <= bottomRight.getX() + OFF_SCREEN_BORDER_AMOUNT
      && point.getY() >= bottomRight.getY() - OFF_SCREEN_BORDER_AMOUNT
      && point.getY() <= topLeft.getY() + OFF_SCREEN_BORDER_AMOUNT);
}

/**************************************************************************
 * GAME :: HANDLE COLLISIONS
 * Check for a collision between a rock and a bullet.
 **************************************************************************/
// void Game :: handleCollisions()
// {
//    // now check for a hit (if it is close enough to any live bullets)
//    for (int i = 0; i < bullets.size(); i++)
//    {
//       if (bullets[i].isAlive())
//       {
//          // this bullet is alive, see if its too close

//          // check if the rock is at this point (in case it was hit)
//          if (rock != NULL && rock -> isAlive())
//          {
//             // BTW, this logic could be more sophisiticated, but this will
//             // get the job done for now...
//             if (fabs(bullets[i].getPoint().getX() - rock -> getPoint().getX()) < CLOSE_ENOUGH
//                 && fabs(bullets[i].getPoint().getY() - rock -> getPoint().getY()) < CLOSE_ENOUGH)
//             {
//                //we have a hit!
               
//                // hit the rock
//                int points = rock -> hit();
//                score += points;
               
//                // the bullet is dead as well
//                bullets[i].kill();

//                // hit count (NOT POINTS!!!)
//                ++hitCount;

//                // accuracy

//                if (hitCount)
//                {
//                   assert(hitCount > 0);
//                   accuracy = hitCount / roundsFired * 100;
//                }
//             }
//          }
//       } // if bullet is alive
      
//    } // for bullets
// }

/**************************************************************************
 * GAME :: CLEAN UP ZOMBIES
 * Remove any dead objects (take bullets out of the list, deallocate rock)
 **************************************************************************/
// void Game :: cleanUpZombies()
// {
//    // check for dead rock
//    if (rock != NULL && !rock -> isAlive())
//    {
//       // the rock is dead, but the memory is not freed up yet
      
//       // TODO: Clean up the memory used by the rock
//       delete rock;
//       rock = NULL;   
//    }
   
//    // Look for dead bullets
//    vector<Bullet>::iterator bulletIt = bullets.begin();
//    while (bulletIt != bullets.end())
//    {
//       Bullet bullet = *bulletIt;
//       // Asteroids Hint:
//       // If we had a list of pointers, we would need this line instead:
//       //Bullet* pBullet = *bulletIt;
      
//       if (!bullet.isAlive())
//       {
//          // If we had a list of pointers, we would need to delete the memory here...
         
         
//          // remove from list and advance
//          bulletIt = bullets.erase(bulletIt);
//       }
//       else
//       {
//          bulletIt++; // advance
//       }
//    }
   
// }

/***************************************
 * GAME :: HANDLE INPUT
 * accept input from the user
 ***************************************/
// void Game :: handleInput(const Interface & ui)
// {
//    // Change the direction of the rifle
//    if (ui.isLeft())
//    {
//       rifle.moveLeft();
//    }
   
//    if (ui.isRight())
//    {
//       rifle.moveRight();
//    }
   
//    // Check for "Spacebar
//    if (ui.isSpace())
//    {
//       Bullet newBullet;
//       newBullet.fire(rifle.getPoint(), rifle.getAngle());

//       roundsFired++;
      
//       bullets.push_back(newBullet);
//    }
// }

/*********************************************
 * GAME :: DRAW
 * Draw everything on the screen
 *********************************************/
void Game :: draw(const Interface & ui)
{
    //check if you have a valid rock and if it's alive
    // then call it's draw method
    vector<Rock*> :: iterator it;
    for (it = rocks.begin(); it < rocks.end(); ++it)
    {
        if ((*it)->isAlive())
            (*it)->draw();
    }
    
    //check if you have a valid ship and if it's alive
    // then call it's draw method
    // if (ship != NULL)
    //     if (ship->isAlive())
    //         ship->draw();
    
    // draw the bullets, if they are alive
    // vector<Bullet*> :: iterator bit;
    // for (bit = bullets.begin(); bit < bullets.end(); ++bit)
    // {
    //     if ((*bit)->isAlive())
    //         (*bit)->draw();
    // }
    
    // if (score == 40 & level == 1)
    // {
    //     for (int i = 0; i < 4; i++)
    //         createUltraShip();
        
    //     level = 2;
    // }
    
    // Put the score on the screen
    // Point scoreLocation;
    // scoreLocation.setX(-195);
    // scoreLocation.setY(195);
    
    // drawNumber(scoreLocation, score);

}

// You may find this function helpful...

/**********************************************************
 * Function: getClosestDistance
 * Description: Determine how close these two objects will
 *   get in between the frames.
 **********************************************************/
/*
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
*/
