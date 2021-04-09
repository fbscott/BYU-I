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
#include <list>

using namespace std;

/***********************************************************************
 * 
 * Description:
 ***********************************************************************/

void promptNumbers(list <int> & numbers)
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

void displayNumbers (list <int> & numbers)
{
   /*
   for (int i = 0; i < numbers.size(); i++)
   {
      cout << numbers[i] << endl;
   }

   */
for (list <int> :: reverse_iterator it = numbers.rbegin();
   it != numbers.rend();
   it++)
{
      cout << *it << endl;
}
}

void removeOdds(list <int> & numbers)
{
   for (list <int> :: iterator it = numbers.begin(); it != numbers.end(); /* blank */ )
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
   list <int> numbers;

   promptNumbers(numbers);
   displayNumbers(numbers);

   removeOdds(numbers);
   displayNumbers(numbers);

   return 0;
}
