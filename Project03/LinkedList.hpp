//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.
//
//  Modified by Tiziana Ligorio for Hunter College CSCI 235
//  Removed Exception Handling becuse not yet covered and
//  added Project3A specific methods

/** ADT list: Singly linked list implementation.
    Listing 9-2.
    @file LinkedList.h */

#ifndef LINKED_LIST_
#define LINKED_LIST_

#include "Node.hpp"

template<class T>
class LinkedList
{

public:
   LinkedList();
   LinkedList(const LinkedList<T>& a_list);
   virtual ~LinkedList();

   bool isEmpty() const;
   int getLength() const;
   bool insert(int new_position, const T& new_entry);
   bool remove(int position);
   void clear();
   T getEntry(int position) const;


   /***************** PROJECT-SPECIFIC PUBLIC METHODS ****************/

    // A  wrapper to a recursive method that inverts the contents of the list
    // @post the contents of the list are inverted such that
    //      the item previously at position 1 is at position item_count_,
    //      the item previously at position 2 is at position item_count_-1 ...
    //      the item previously at position ⌊item_count/2⌋ is at position ⌈item_count_/2⌉
    void invert();



private:
    Node<T>* head_ptr_; // Pointer to first node in the chain;
    // (contains the first entry in the list)
    int item_count_;           // Current count of list items

    // Locates a specified node in this linked list.
    // @pre  position is the number of the desired node;
    //       position >= 1 and position <= item_count_.
    // @post  The node is found and a pointer to it is returned.
    // @param position  The number of the node to locate.
    // @return  A pointer to the node at the given position.
    Node<T>* getNodeAt(int position) const;


       /***************** PROJECT-SPECIFIC PRIVATE METHODS ****************/

    //recursively inverts the contents of he list, used for safe programming to avoid
    //exposing pointers to list in public methods
    // @post the contents of the list are inverted such that
    //      the item previously at position 1 is at position item_count_,
    //      the item previously at position 2 is at position item_count_-1 ...
    //      the item previously at position ⌊item_count/2⌋ is at position ⌈item_count_/2⌉
    void invertRest(Node<T>* current_first_ptr);

}; // end LinkedList

#include "LinkedList.cpp"
#endif
