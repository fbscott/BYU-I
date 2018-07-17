/*********************************************************************
 * File: game.h
 * Description: Defines the game class for Asteroids
 *********************************************************************/
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"

// my custom classes
#include "rocks.h"
#include "ship.h"
#include "bullet.h"

/*****************************************************************************
 * GAME
 * The main game class containing all the state information.
 ****************************************************************************/
class Game
{
   private:
      // int score;
      // int roundsFired;
      // int hitCount;
      // int accuracy;
      // The coordinates of the screen
      Point topLeft;
      Point bottomRight;
      
      std::vector<Rock*> rocks;
      // declare a new ship object
      Ship * ship;
      // std::vector<Bullet*> bullets;

      bool isOnScreen(const Point & point);
      // void advanceBullets();
      void advanceRocks();
      // void handleCollisions();
      // void cleanUpZombies();
      void createBigRock();
      void createMediumRock(Point, int);
      void createSmallRock(Point, int);
      float getClosestDistance(const FlyingObject &obj1, const FlyingObject &obj2) const;

   public:
      Game();
      Game(Point topLeft, Point bottomRight);
   
      void advance();
      void advanceShip();
      void draw(const Interface & ui);
      void handleInput(const Interface & ui);
};

#endif /* GAME_H */
