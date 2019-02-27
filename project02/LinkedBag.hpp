//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.
//  Modified by Tiziana Ligorio 2019 for CSCI 235 Hunter College

/** ADT bag: Link-based implementation.
    @file LinkedBag.h
    Listing 4-3 */
#ifndef LINKED_BAG_
#define LINKED_BAG_

#include <vector>
#include <cstdlib>
#include <algorithm>
#include "Node.hpp"

template<class T>
class LinkedBag
{
public:
   LinkedBag();
   LinkedBag(const LinkedBag<T>& a_bag); // Copy constructor
   ~LinkedBag();   

    /**
     @param a_bag to be combined with the contents of this (the calling) bag
     @return a new LinkedBag that contains all elements from this bag (items_)and from a_bag. Note that it may contain duplicates
    */
    LinkedBag<T> bagUnion(const LinkedBag<T>& a_bag) const; 
    
    /**
     @param a_bag to be intersected with the contents of this (the calling) bag
     @return a new LinkedBag that contains the intersection of the contents of this bag and those of the argument a_bag. This intersection does not contain duplicates (e.g. every element occurring in BOTH bags will be found only once in the intersection, no matter how many occurrences in the original bags) as in set intersection A ∩ B
     */
    LinkedBag<T> bagIntersectionNoDuplicates(const LinkedBag<T>& a_bag) const;

    /**
     @param a_bag whose contents are to be copied to this (the calling) bag
     @post this (the calling) bag has same contents as a_bag
     */
    void operator= (const LinkedBag<T>& a_bag);

    /**
     @param new_entry to be added to the bag
     @post new_entry is added at the end of the chain preserving the order of items in the bag
     @return true if added successfully, false otherwise
    */
    bool addToEnd(const T& new_entry);

    /**
     @param an_entry to be removed from the bag
     @post the first occurrence of an_entry starting from the head node is removed from the chain preserving the order of the remaining items in the bag
     @return true if removed successfully, false otherwise
    */
    bool removeRetainOrder(const T& an_entry);

                    // Destructor 
   int getCurrentSize() const;
   bool isEmpty() const;
   bool add(const T& new_entry);
   bool remove(const T& an_entry);
   void clear();
   bool contains(const T& an_entry) const;
   int getFrequencyOf(const T& an_entry) const;
   std::vector<T> toVector() const;


private:
    Node<T>* head_ptr_;     // Pointer to first node
    int item_count_;           // Current count of bag items

    /**
     @return Returns either a pointer to the node containing a given entry
     or the null pointer if the entry is not in the bag.
     */
    Node<T>* getPointerTo(const T& target) const;


}; // end LinkedBag

#include "LinkedBag.cpp"
#endif
