//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

///////////////////////////
//FILE NAME: ArrayBag.cpp//
///////////////////////////

////////////////
//Contributers//
////////////////

///////////////////////////////////////////////

// NAME                   DATE           CHANGE
// Dillon Dragomir        07-14-2017     Implemented Member Functions
// Andrew Piment          07-14-2017     Implemented Member Functions

///////////////////////////////////////////////

////////////////
//DEPENDANCIES//
////////////////
 @file ArrayBag.cpp */

#include <cstddef>
#include <typeinfo>
#include "ArrayBag.h"

template<class ItemType>
ArrayBag<ItemType>::ArrayBag(): itemCount(0), maxItems(DEFAULT_CAPACITY)
{
}  // end default constructor


// Implement a constructor overload which takes a template array along with
// number of entries
// Template create arrayBag of type ItemType
template<class ItemType>
ArrayBag<ItemType>::ArrayBag(ItemType entries[], int entryCount) :
itemCount(entryCount), maxItems(DEFAULT_CAPACITY)
{
    // For each entry in entries, add an entry to items
    // The for loop is needed to make a deep copy in the ArrayBag class
    for (int i = 0; i < entryCount; i++) {
        items[i] = entries[i];
    }

    // Set the objects itemCount equal to the passed in entryCount
    itemCount = entryCount;

}  // end paremeter constructor

template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
	// Public member function to return number of entries in 
	return itemCount;
}  // end getCurrentSize

template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
	//Boolean statment to determine if itemCount is 0
	return itemCount == 0;
}  // end isEmpty

template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& newEntry)
{
	//Checks whether the array is long enough to add another item
	bool hasRoomToAdd = (itemCount < maxItems);
	if (hasRoomToAdd)
	{
		items[itemCount] = newEntry;
		itemCount++;
	}  // end if

	return hasRoomToAdd;
}  // end add


template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& anEntry)
{
	// Gets index of a value
    int locatedIndex = getIndexOf(anEntry);
	bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
	if (canRemoveItem)
	{
		itemCount--;
		items[locatedIndex] = items[itemCount];
	}  // end if

	return canRemoveItem;
}  // end remove

template<class ItemType>
void ArrayBag<ItemType>::clear()
{
	itemCount = 0;
}  // end clear

template<class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
   int frequency = 0;
   int curIndex = 0;       // Current array index
   while (curIndex < itemCount)
   {
      if (items[curIndex] == anEntry)
      {
         frequency++;
      }  // end if

      curIndex++;          // Increment to next entry
   }  // end while

   return frequency;
}  // end getFrequencyOf

template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const
{
	return getIndexOf(anEntry) > -1;
}  // end contains

template<class ItemType>
std::vector<ItemType> ArrayBag<ItemType>::toVector() const
{
   std::vector<ItemType> bagContents;
	for (int i = 0; i < itemCount; i++)
		bagContents.push_back(items[i]);

   return bagContents;
}  // end toVector

/** Implement a member function sum which counts integer numbers and returns
 * the sum as a double variable
 * @pre Check if the template is of integer data type
 * @post If the template is of other than integer return -1
 * @param void
 * @return sum of integers present in the array **/
template<class ItemType>
double ArrayBag<ItemType>::sum() const
{

     double sumVal = 0;

     // Check that the ItemType is a value of int
     if (typeid(ItemType) == typeid(int))
     {

         // For each item, add the value to the sum
         for (int i = 0; i < itemCount; i++)
         {
             sumVal += items[i];
         }
     }
     else
        return -1;

     // Return the sum Value
     return sumVal;

} // end sum

/** Implement a member function which replaces existing entry with new
 * entry.
 * @param oldItem from the array and newItem from the array
 * @return 1 if the replacement is done successfully or else 0 **/
template<class ItemType>
bool ArrayBag<ItemType>::replace(const ItemType oldEntry, const ItemType newEntry)
{
    bool hasReplaced = false;
    int nextIndex = 0;

    // While the index is a feasible number or the starting 0 and the new entry is not equal to the old entry
    while (nextIndex >= 0 && newEntry != oldEntry)
    {
        // Find the old entry
        nextIndex = getIndexOf(oldEntry);

        // If the index is a real value
        if(nextIndex >= 0)
        {
            // Replace the value at the index
            items[nextIndex] = newEntry;

            // Set the flag to true
            hasReplaced = true;
        }
    }

    // Return the flag
    return hasReplaced;

} // end replace

/** Implement a member function to merge a new array into existing array
 * @param New array ADT object
 * @return 1(true) if successful, or 0(false) if not **/
template<class ItemType>
bool ArrayBag<ItemType>::merge(const ArrayBag<ItemType>& secondBag)
{
    bool returnVal;

    // If the max size is not big enough, expand the size to the addtion of the sizes
    if(maxItems < getCurrentSize()+secondBag.getCurrentSize())
        maxItems = getCurrentSize()+secondBag.getCurrentSize();

    // Loop through each item in the second bag and add it to the current set of items
    for (int i = 0; i < secondBag.getCurrentSize(); i++)
    {
        bool thisReturnVal = add(secondBag.items[i]);
        if (thisReturnVal)
            returnVal = true;;
    }

    // Return the bool that tracks whether the add was successful
    return returnVal;

} // end merge

// private
template<class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType& target) const
{
	bool found = false;
   int result = -1;
   int searchIndex = 0;

   // If the bag is empty, itemCount is zero, so loop is skipped
   while (!found && (searchIndex < itemCount))
   {
      if (items[searchIndex] == target)
      {
         found = true;
         result = searchIndex;
      }
      else
      {
         searchIndex++;
      }  // end if
   }  // end while

   return result;
}  // end getIndexOf
