//
//  List.cpp
//  List
//
//  Modified by David Yuen on 03/01/19 for CSCI 235 Project 2B
//  Added function scanSublist(size_t position)
//  Project 2B
//  Created by Tiziana Ligorio on 10/21/18.
//  Copyright © 2018 Tiziana Ligorio. All rights reserved.
//  Changed > and < to >= and <= for Extra Credit

#include "List.hpp"

template<class T>
List<T>::List(): item_count_(0), first_(nullptr), last_(nullptr){} // constructor 


//copy constructor
template<class T>
List<T>::List(const List<T>& a_list)
{
    item_count_ = a_list.item_count_;
    Node<T>* orig_chain_ptr = a_list.first_;  // Points to nodes in original chain

    if (orig_chain_ptr == nullptr)
    {// Original chain is empty
        first_ = nullptr;
        last_ = nullptr;
    }
    else
    {
        // Copy first node
        first_ = new Node<T>();
        first_->setPrevious(nullptr);
        first_->setItem(orig_chain_ptr->getItem());

        // Copy remaining nodes
        Node<T>* new_chain_ptr = first_;      			// Points to last node in new chain
        orig_chain_ptr = orig_chain_ptr->getNext();     // Advance original-chain pointer

        while (orig_chain_ptr != nullptr)
        {
            // Get next item from original chain
            T next_item = orig_chain_ptr->getItem();

            // Create a new node containing the next item
            Node<T>* new_node_ptr = new Node<T>(next_item);

            // Link new node to end of new chain
            new_chain_ptr->setNext(new_node_ptr);
            new_node_ptr->setPrevious(new_chain_ptr);

            // Advance pointer to new last node
            new_chain_ptr = new_chain_ptr->getNext();

            // Advance original-chain pointer
            orig_chain_ptr = orig_chain_ptr->getNext();
        }  // end while

        // Flag end of chain
        new_chain_ptr->setNext(nullptr);
        last_ = new_chain_ptr;
    }  // end if
} // copy constructor


// destructor 
template<class T>
List<T>::~List(){ clear();}

/**@return true if list is empty - item_count_ == 0 */
template<class T>
bool List<T>::isEmpty() const{ return (item_count_ == 0);}


 /**@return the number of items in the list - item_count_ */
template<class T>
size_t List<T>::getLength() const{return item_count_;}


/**
 @param position indicating point of insertion
 @param new_element to be inserted in list
 @post new_element is added at position in list (before the node previously at that position)
 @return true always - it always inserts, if position > item_count_ it inserts at end of list */
template<class T>
bool List<T>::insert(size_t position, const T& new_element)
{
    // Create a new node containing the new entry and get a pointer to position
    Node<T>* new_node_ptr = new Node<T>(new_element);
    Node<T>* pos_ptr = getPointerTo(position);

    // Attach new node to chain
    if (first_ == nullptr)
    {
        //Chain is empty -  Insert first node
        new_node_ptr->setNext(nullptr);
        new_node_ptr->setPrevious(nullptr);
        first_ = new_node_ptr;
        last_ = new_node_ptr;

    }
    else if (pos_ptr == first_)
    {
        // Insert new node at beginning of list
        new_node_ptr->setNext(first_);
        new_node_ptr->setPrevious(nullptr);
        first_->setPrevious(new_node_ptr);
        first_ = new_node_ptr;

    }
    else if (pos_ptr == nullptr)
    {
        //insert at end of list
        new_node_ptr->setNext(nullptr);
        new_node_ptr->setPrevious(last_);
        last_->setNext(new_node_ptr);
        last_ = new_node_ptr;

    }
    else
    {
        // Insert new node before node to which pos_ptr points
        new_node_ptr->setNext(pos_ptr);
        new_node_ptr->setPrevious(pos_ptr->getPrevious());
        pos_ptr->getPrevious()->setNext(new_node_ptr);
        pos_ptr->setPrevious(new_node_ptr);

    }  // end if

    item_count_++;  // Increase count of entries
    return true;    //It will always insert, if pos_ptr is nullptr it will insert at end
}//end insert


/**
 @param position indicating point of deletion
 @post node at position is deleted, if any. List order is retains
 @return true if ther eis a node at position to be deleted, false otherwise */
template<class T>
bool List<T>::remove(size_t position)
{
    //get pointer to position
    Node<T>* pos_ptr = getPointerTo(position);

    if(pos_ptr == nullptr)
        return false;
    else
    {
        // Remove node from chain

        if (pos_ptr == first_)
        {
            // Remove first node
            first_ = pos_ptr->getNext();
            first_->setPrevious(nullptr);

            // Return node to the system
            pos_ptr->setNext(nullptr);
            delete pos_ptr;
            pos_ptr = nullptr;
        }
        else if (pos_ptr == last_)
        {
            //remove last node
            last_ = pos_ptr->getPrevious();
            last_->setNext(nullptr);

            // Return node to the system
            pos_ptr->setPrevious(nullptr);
            delete pos_ptr;
            pos_ptr = nullptr;

        }
        else
        {
            //Remove from the middle
            pos_ptr->getPrevious()->setNext(pos_ptr->getNext());
            pos_ptr->getNext()->setPrevious(pos_ptr->getPrevious());

            // Return node to the system
            pos_ptr->setNext(nullptr);
            pos_ptr->setPrevious(nullptr);
            delete pos_ptr;
            pos_ptr = nullptr;

        }

        item_count_--;  // decrease count of entries
        return true;
    }

}//end remove


/**
 @pre assumes there is an item at position - NO ERROR HANDLING
 @param position of item to be retrieved
 @return the item at position in list if there is one, otherwise it returns a dummy UNITIALIZED object of type T -- temporary suboptimal solution in place of error handling to be discussed later in the course  */
template<class T>
T List<T>::getItem(size_t position) const
{
    T dummy;
    Node<T>* pos_ptr = getPointerTo(position);
    if(pos_ptr != nullptr)
        return pos_ptr->getItem();
    else
        return dummy;
}

/**@post the list is empty and item_count_ == 0*/
template<class T>
void List<T>::clear()
{
    Node<T>* node_to_delete = first_;
    while (first_ != nullptr)
    {
        first_ = first_->getNext();

        // Return node to the system
        node_to_delete->setNext(nullptr);
        node_to_delete->setPrevious(nullptr);
        delete node_to_delete;

        node_to_delete = first_;
    }  // end while
    // head_ptr_ is nullptr; node_to_delete is nullptr
    last_ = nullptr;
    item_count_ = 0;
}//end clear



//position follows classic indexing from 0 to item_count_-1
//if position > item_count it returns nullptr
template<class T>
Node<T>* List<T>::getPointerTo(size_t position) const
{

    Node<T>* find = nullptr;
    if(position < item_count_)
    {
        find = first_;
        for(size_t i = 0; i < position; ++i)
        {
            find = find->getNext();
        }
    }

    return find;
}//end getPointerTo


//**** PROJECT-SPECIFIC METHODS ***//


/**
 @pre assumes std::cout << is defined for objects of type T (can be sent to standard output) -- This method is not general, thus not appropriate for a templated class, it is provided for project debugging purposes
 @post traverses the list and prints (std::cout) every item in the list*/
template<class T>
void List<T>::traverse()
{
    for(Node<T>*  ptr = first_; ptr != nullptr; ptr = ptr->getNext())
    {
        std::cout << ptr->getItem() << " ";
    }
    std::cout << std::endl;
}


/**
@pre assumes position is valid, if position is > item_count_ it returns an
empty List, also assumes that operators <= and >= are defined on type T
@param position contained in the sorted/increasing (first <= position <=
last) sublist to be generated
@return a sublist containing the item at position consisting of sorted/
increasing items (first <= position <= last)
*/
template<class T>
List<T> List<T>::scanSublist(size_t position)
{
    List<T> final_list;                                 //Final list that will be returned

    T start_item = getItem(position);                   //Item of start node

    ///Returns an empty List<T> if the calling list is empty
    if(isEmpty() || position > item_count_)
        return final_list;

    Node<T>* start_Node = getPointerTo(position);       //Position of node we're looking for
    Node<T>* cycle_Node;                                //Node used to traverse list

    final_list.insert(1, start_item);                   //Insert the item we are seraching for

    /**
     * Only done if original item is not at already end of list
     * Because the original item at position is already inserted handled on line 293
     */
    if(start_Node->getNext() != NULL)
    {
        cycle_Node = start_Node;                        //At starting point      
        int n_count = 2;                                //counter used to insert at next position

        //Insert next item if next item is greater than current item AND not at end of list
        while(cycle_Node->getNext()->getItem() >= cycle_Node->getItem() && cycle_Node->getNext()->getNext() != NULL)
        {
            final_list.insert(n_count,cycle_Node->getNext()->getItem());
            cycle_Node = cycle_Node->getNext();         //traverses right
            n_count++;
        }

        //EDGE CASE: item at end of list is greater than current item
        if(cycle_Node->getNext()->getNext() == NULL && cycle_Node->getItem() >= cycle_Node->getPrevious()->getItem())
        {
            final_list.insert(n_count,cycle_Node->getNext()->getItem());
        }
    }
    
    /**
     * Only done if original item is not at already beginning of list
     * Because the original item at position is already inserted handled on line 293
     */
    if(start_Node->getPrevious() != NULL)
    {
        cycle_Node = start_Node->getPrevious();         //Starting point at node before original position

        //Checks if current item is less than its next item(to the right)
        while(cycle_Node->getItem() <= cycle_Node->getNext()->getItem() && cycle_Node->getPrevious() != NULL)
        {
            final_list.insert(0,cycle_Node->getItem());
            cycle_Node = cycle_Node->getPrevious();     //traverses left
        }

        //EDGE CASE: item at beginning of list is less than its next item
        if(cycle_Node->getPrevious() == NULL && cycle_Node->getItem() <= cycle_Node->getNext()->getItem())
        {
            final_list.insert(0,cycle_Node->getItem());
        }
    }

    //return List<T>
    return final_list;
}//return scanSublist
