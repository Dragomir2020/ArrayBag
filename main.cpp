//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

///////////////////////
//FILE NAME: main.cpp//
///////////////////////

////////////////
//Contributers//
////////////////

///////////////////////////////////////////////

// NAME                   DATE           CHANGE
// Dillon Dragomir        07-14-2017     Upload file
// Andrew Piment          07-14-2017     Upload file

///////////////////////////////////////////////

////////////////
//DEPENDANCIES//
////////////////
#include <iostream>
#include <string>
#include "ArrayBag.h"

// Used in main function to display items in the bag
void displayBag(ArrayBag<std::string>& bag)
{
	std::cout << "The bag contains " << bag.getCurrentSize()
        << " items:" << std::endl;
   std::vector<std::string> bagItems = bag.toVector();
   
   int numberOfEntries = (int) bagItems.size();
   for (int i = 0; i < numberOfEntries; i++)
   {
      std::cout << bagItems[i] << " ";
   }  // end for
	std::cout << std::endl << std::endl;
}  // end displayBag

// Tests the member functions of ArrayBag ADT
void bagTester(ArrayBag<std::string>& bag)
{
   std::cout << "isEmpty: returns " << bag.isEmpty() 
        << "; should be 1 (true)" << std::endl;
   displayBag(bag);

	std::string items[] = {"one", "two", "three", "four", "five", "one"};
   std::cout << "Add 6 items to the bag: " << std::endl;
	for (int i = 0; i < 6; i++)
   {
		bag.add(items[i]);
	}  // end for
   
   displayBag(bag);
   
   std::cout << "isEmpty: returns " << bag.isEmpty() 
        << "; should be 0 (false)" << std::endl;
	
   std::cout << "getCurrentSize: returns " << bag.getCurrentSize() 
        << "; should be 6" << std::endl;
   
   std::cout << "Try to add another entry: add(\"extra\") returns " 
        << bag.add("extra") << std::endl;      
   
   std::cout << "contains(\"three\"): returns " << bag.contains("three")
        << "; should be 1 (true)" << std::endl;
   std::cout << "contains(\"ten\"): returns " << bag.contains("ten")
        << "; should be 0 (false)" << std::endl;
   std::cout << "getFrequencyOf(\"one\"): returns "
        << bag.getFrequencyOf("one") << " should be 2" << std::endl;
   std::cout << "remove(\"one\"): returns " << bag.remove("one")
        << "; should be 1 (true)" << std::endl;
   std::cout << "getFrequencyOf(\"one\"): returns "
        << bag.getFrequencyOf("one") << " should be 1" << std::endl;
   std::cout << "remove(\"one\"): returns " << bag.remove("one")
        << "; should be 1 (true)" << std::endl;
   std::cout << "remove(\"one\"): returns " << bag.remove("one")
        << "; should be 0 (false)" << std::endl;
   std::cout << "replace(\"two, with six\"): returns " << bag.replace("two",
   "six")<< "; should be 1 (true)" << std::endl;
   std::cout << std::endl;
   
   displayBag(bag);
   
   std::cout << "After clearing the bag, ";
   bag.clear();
   
   std::cout << "isEmpty: returns " << bag.isEmpty()
        << "; should be 1 (true)" << std::endl;
}  // end bagTester

// Main function creates new ArrayBag and uses member functions to interact with it
int main()
{
    ArrayBag<std::string> bag;
    int array[] = {1,2,3};
    ArrayBag<int> firstBag(array, 3);
    ArrayBag<int> secondBag(array, 3);
	std::cout << "Testing the Array-Based Bag:" << std::endl;
    std::cout << "The initial bag is empty." << std::endl;
	bagTester(bag);
    std::cout << "The sum of integer array should be 6, your answer is " <<
    firstBag.sum() << std::endl;
    std::cout << "Merging firstBag and secondBag" << std::endl;
    bool ret = firstBag.merge(secondBag);
    std::cout << "The size of new bag should be 6, your output is " <<
    firstBag.getCurrentSize() << std::endl;
    std::cout << "All done!" << std::endl;
   
    return 0;
}  // end main

