/**********************************************************************
 * File: ta10.cpp
 * Author: Group 1 - 
 *
 * Description: Use this file as a starting point for Team Activity 03.
 *    You do not need to "submit" your code, but rather, answer the
 *    questions in the I-Learn assessment.
 **********************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/***********************************************************************
 * 
 * Description:
 ***********************************************************************/

void promptNumbers(vector <int> & numbers)
{
   int tempNum;
   do
   {
      cout << "int until you enter zero (0): ";
      cin >> tempNum;
      if (tempNum)
      {
         numbers.push_back(tempNum);
      }
      
   }
   while (tempNum);
}

void displayNumbers (vector <int> & numbers)
{
   /*
   for (int i = 0; i < numbers.size(); i++)
   {
      cout << numbers[i] << endl;
   }

   */
for (vector <int> :: iterator it = numbers.begin();
   it != numbers.end();
   it++)
{
      cout << *it << endl;
}
}

void removeOdds(vector <int> & numbers)
{
   for (vector <int> :: iterator it = numbers.begin(); it != numbers.end(); /* blank */ )
   {
      if (*it % 2 == 1)
      {
         it = numbers.erase(it);
      }
      else 
      it++;
   }
   
}

int main()
{
   vector <int> numbers;

   promptNumbers(numbers);
   displayNumbers(numbers);

   removeOdds(numbers);
   displayNumbers(numbers);

   return 0;
}
