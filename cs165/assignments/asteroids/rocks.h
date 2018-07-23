/*****************************************************************************
 * Header File:
 *    Rock : The representation of a rock
 * Author:
 *    Scott Currell
 * Summary:
 *    Rock class. Children will inherit from this class.
 ****************************************************************************/

#ifndef rocks_h
#define rocks_h

#define BIG_ROCK_SIZE 16
#define MEDIUM_ROCK_SIZE 8
#define SMALL_ROCK_SIZE 4

#define BIG_ROCK_SPIN 2
#define MEDIUM_ROCK_SPIN 5
#define SMALL_ROCK_SPIN 10

#include "flyingObject.h"
#include "uiDraw.h"

/*****************************************************************************
 * ROCK
 ****************************************************************************/
class Rock : public FlyingObject
{
   private:
      int radius;
      int rockID;

   public:
      // constructor
      Rock();

      // getters
      int getRadius() const { return radius; }
      int getRockID() const { return rockID; }

      // setters
      void setRadius(int radius) { this -> radius = radius; }
      void setRockID(int rockID) { this -> rockID = rockID; }

      // pure virtual functions
      virtual void hit() =0;

      // methods
      virtual void kill();
};

/*****************************************************************************
 * BIG ROCK
 ****************************************************************************/
class BigRock : public Rock
{
   private:
      int angle;
      int rotation;

   public:
      BigRock();
      virtual void draw();
      virtual void hit();
      int hits;
};

/*****************************************************************************
 * MEDIUM ROCK
 ****************************************************************************/
class MediumRock : public Rock
{
   private:
      int angle;
      int rotation;

   public:
      MediumRock(Point, int);
      virtual void draw();
      virtual void hit();
};

/*****************************************************************************
 * SMALL ROCK
 ****************************************************************************/
class SmallRock : public Rock
{
   private:
      int rotation;

   public:
      SmallRock(Point, int);
      virtual void draw();
      virtual void hit();
};

#endif /* rocks_h */
