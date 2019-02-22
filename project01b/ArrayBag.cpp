//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

//  Modified by Tiziana Ligorio for CSCI 235 Hunter college 2019



/** Implementation file for the class ArrayBag.
 @file ArrayBag.cpp */

#include "ArrayBag.hpp"
#include <cstddef>

/** default constructor**/
template<class T>
ArrayBag<T>::ArrayBag(): item_count_(0)
{
}  // end default constructor


/**
 @return item_count_ : the current size of the bag
 **/
template<class T>
int ArrayBag<T>::getCurrentSize() const
{
	return item_count_;
}  // end getCurrentSize


/**
 @return true if item_count_ == 0, false otherwise
 **/
template<class T>
bool ArrayBag<T>::isEmpty() const
{
	return item_count_ == 0;
}  // end isEmpty


/**
 @return true if new_etry was successfully added to items_, false otherwise
 **/
template<class T>
bool ArrayBag<T>::add(const T& new_entry)
{
	bool has_room = (item_count_ < DEFAULT_CAPACITY);
	if (has_room)
	{
		items_[item_count_] = new_entry;
		item_count_++;
	}  // end if
    
	return has_room;
}  // end add


/**
 @return true if an_etry was successfully removed from items_, false otherwise
 **/
template<class T>
bool ArrayBag<T>::remove(const T& an_entry)
{
   int found_index = getIndexOf(an_entry);
	bool can_remove = !isEmpty() && (found_index > -1);
	if (can_remove)
	{
		item_count_--;
		items_[found_index] = items_[item_count_];
	}  // end if
    
	return can_remove;
}  // end remove


/**
 @post item_count_ == 0
 **/
template<class T>
void ArrayBag<T>::clear()
{
	item_count_ = 0;
}  // end clear


/**
 @return the number of times an_entry is found in items_
 **/
template<class T>
int ArrayBag<T>::getFrequencyOf(const T& an_entry) const
{
   int frequency = 0;
   int cun_index = 0;       // Current array index
   while (cun_index < item_count_)
   {
      if (items_[cun_index] == an_entry)
      {
         frequency++;
      }  // end if
      
      cun_index++;          // Increment to next entry
   }  // end while
   
   return frequency;
}  // end getFrequencyOf


/**
 @return true if an_etry is found in items_, false otherwise
 **/
template<class T>
bool ArrayBag<T>::contains(const T& an_entry) const
{
	return getIndexOf(an_entry) > -1;
}  // end contains


/**
 @return a vector having the same cotntents as items_
 **/
template<class T>
std::vector<T> ArrayBag<T>::toVector() const
{
   std::vector<T> bag_contents;
	for (int i = 0; i < item_count_; i++)
		bag_contents.push_back(items_[i]);
      
   return bag_contents;
}  // end toVector

/**
 @return a new ArrayBag that contains all elements from this bag(items_) and as many elements from arg a_bag as space allows (max size of starting bag) Duplicate items are allowed Note: Because ArrayBag is of fixed size, bagUnion will copy the contents of the calling bag first and then whatever fits from the argument a_bag 
 **/
template<class T>
ArrayBag<T> ArrayBag<T>::bagUnion(const ArrayBag<T>& a_bag) const{
   ArrayBag<T> new_bag;
   for(int i=0; i < item_count_; i++){
      new_bag.add(items_[i]);
   }
   std::vector<T> a_bag_vector = a_bag.toVector();
   for(int i = 0; i < a_bag.getCurrentSize(); i++){
      new_bag.add(a_bag_vector[i]);
   }
   return new_bag;
}

/**
 @return a new ArrayBag that contains the intersection of the contents of this bag and those of the argument a_bag. This intersection does not contain duplicates (e.g. every element occurring in BOTH bags will be found only once in the intersection, no matter how many occurrences in the original bags) as in set intersection A ∩ B
 */
template<class T>
ArrayBag<T> ArrayBag<T>::bagIntersectionNoDuplicates(const ArrayBag<T>& a_bag) const{
   ArrayBag<T> new_bag;
   std::vector<T> a_bag_vector = a_bag.toVector();

   for(int i = 0; i < item_count_; i++){
      if(!new_bag.contains(items_[i]) && a_bag.contains(items_[i])){
         new_bag.add(items_[i]);
      }
   }

   for(int i = 0; i < a_bag.getCurrentSize(); i++){
      if(!new_bag.contains(a_bag_vector[i]) && contains(a_bag_vector[i])){
         new_bag.add(a_bag_vector[i]);
      }
   }
   
   return new_bag;
}

/**
 @param a_bag to be subtracted from this bag
 @return a new ArrayBag that contains only those items that occur in this bag or in a_bag but not in both, and it does not contain duplicates
 */
template<class T>
ArrayBag<T> ArrayBag<T>::bagDifference(const ArrayBag<T>& a_bag) const{
   ArrayBag<T> new_bag;
   std::vector<T> a_bag_vector = a_bag.toVector();

   for(int i = 0; i < item_count_; i++){
      if(!new_bag.contains(items_[i]) && !a_bag.contains(items_[i])){
         new_bag.add(items_[i]);
      }
   }

   for(int i = 0; i < a_bag.getCurrentSize(); i++){
      if(!new_bag.contains(a_bag_vector[i]) && !contains(a_bag_vector[i])){
         new_bag.add(a_bag_vector[i]);
      }
   }
   
   return new_bag;
}

template<class T>
ArrayBag<T> ArrayBag<T>::bagIntersection(const ArrayBag<T>& a_bag) const{
   ArrayBag<T> new_bag;                                                    //output
   ArrayBag<T> tmp_bag1;                                                   // -> bag temp
   for(int i=0; i < item_count_; i++)                                      // -> to tmp1
      tmp_bag1.add(items_[i]);                                             // -> to tmp1
   std::vector<T> a_bag_vector = a_bag.toVector();                         // -> to tmp2
   ArrayBag<T> tmp_bag2;                     
      for(int i=0; i < a_bag.getCurrentSize(); i++)
         tmp_bag2.add(a_bag_vector[i]);
   
   for(int i=0; i < item_count_; i++){
      if(tmp_bag1.contains(items_[i]) && tmp_bag2.contains(items_[i])){
         new_bag.add(items_[i]);
         tmp_bag1.remove(items_[i]);
         tmp_bag2.remove(items_[i]);
      }
   }

   return new_bag;
} 

 
// PRIVATE

/**
 @param target to be found in items_
 @return either the index target in the array items_ or -1, if the array does not containthe target.
 **/
template<class T>
int ArrayBag<T>::getIndexOf(const T& target) const
{
	bool found = false;
   int result = -1;
   int search_index = 0;
   
   // If the bag is empty, item_count_ is zero, so loop is skipped
   while (!found && (search_index < item_count_))
   {
      if (items_[search_index] == target)
      {
         found = true;
         result = search_index;
      } 
      else
      {
         search_index++;
      }  // end if
   }  // end while
   
   return result;
}  // end getIndexOf
