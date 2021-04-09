#ifndef BAG_H
#define BAG_H

/***********************************************************
 * Class: Bag
 * Description: Holds ints...for now
 ***********************************************************/
class Bag
{
private:
   int capacity;
   int size;
   int currentAddIndex;
   int* data;

public:
   Bag(); // Default constructor
				
   // Getters
   int getCapacity() const { return capacity; }
   int getCount()    const { return size; }

   int getItem(int index) { return data[index]; }
   void addItem(int item);
};

Bag :: Bag() {
   data = new int[5];
   capacity = 5;
   size = 0;
   currentAddIndex = 0;
}

Bag :: addItem(int item) {
   data[currentAddIndex] = item;
   currentAddIndex += 1;
}

#endif
