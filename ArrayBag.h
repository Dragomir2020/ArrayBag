//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

///////////////////////////
//FILE NAME: ArrayBag.h//
///////////////////////////

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
/** Header file for an array-based implementation of the ADT bag.
 @file ArrayBag.h */

#ifndef ARRAY_BAG_
#define ARRAY_BAG_

#include "BagInterface.h"

template<class ItemType>
class ArrayBag : public BagInterface<ItemType>
{
private:
	static const int DEFAULT_CAPACITY = 6; // CHANGE THIS FOR LARGER BAG
	ItemType items[DEFAULT_CAPACITY];      // Array of bag items
    int itemCount;                         // Current count of bag items 
    int maxItems;                          // Max capacity of the bag
   
    // Returns either the index of the element in the array items that
    // contains the given target or -1, if the array does not contain 
    // the target.
    int getIndexOf(const ItemType& target) const;   

public:
	ArrayBag();
	int getCurrentSize() const;
	bool isEmpty() const;
	bool add(const ItemType& newEntry);
	bool remove(const ItemType& anEntry);
	void clear();
	bool contains(const ItemType& anEntry) const;
	int getFrequencyOf(const ItemType& anEntry) const;
    std::vector<ItemType> toVector() const;

    //Member functions implimented by me
    ArrayBag(ItemType entries[], int entryCount);
    double sum() const; 
    bool replace(const ItemType oldItem, const ItemType newItem);
    bool merge(const ArrayBag<ItemType>& secondBag);

}; // end ArrayBag

#include "ArrayBag.cpp"
#endif
