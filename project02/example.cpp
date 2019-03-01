//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.
//  Modified by Tiziana Ligorio 2019 for CSCI 235 Hunter College

/** ADT bag: Link-based implementation.
    @file LinkedBag.cpp */

/*Shaina Lowenthal
235 Ligorio
Project 2A
*/

#include "LinkedBag.hpp"
#include "Node.hpp"
#include <cstddef>
#include <iostream>


//creates a place in memory for that list
template<class T>
LinkedBag<T>::LinkedBag() : head_ptr_(nullptr), item_count_(0)
{
}  // end default constructor


//creates the linked list 
template<class T>
LinkedBag<T>::LinkedBag(const LinkedBag<T>& a_bag)
{
	item_count_ = a_bag.item_count_; 
   Node<T>* orig_chain_ptr = a_bag.head_ptr_;  // Points to nodes in original chain

   if (orig_chain_ptr == nullptr)
      head_ptr_ = nullptr;  // Original bag is empty
   else
   {
      // Copy first node
      head_ptr_ = new Node<T>();
      head_ptr_->setItem(orig_chain_ptr->getItem());

      // Copy remaining nodes
      Node<T>* new_chain_ptr = head_ptr_;      // Points to last node in new chain
      orig_chain_ptr = orig_chain_ptr->getNext();     // Advance original-chain pointer

      while (orig_chain_ptr != nullptr)
      {
         // Get next item from original chain
         T next_item = orig_chain_ptr->getItem();

         // Create a new node containing the next item
         Node<T>* new_node_ptr = new Node<T>(next_item);

         // Link new node to end of new chain
         new_chain_ptr->setNext(new_node_ptr);

         // Advance pointer to new last node
         new_chain_ptr = new_chain_ptr->getNext();

         // Advance original-chain pointer
         orig_chain_ptr = orig_chain_ptr->getNext();
      }  // end while

      new_chain_ptr->setNext(nullptr);              // Flag end of chain
   }  // end if
}  // end copy constructor

template<class T>
LinkedBag<T>::~LinkedBag()
{
   clear();
}  // end destructor

template<class T>
bool LinkedBag<T>::isEmpty() const
{
	return item_count_ == 0;
}  // end isEmpty

template<class T>
int LinkedBag<T>::getCurrentSize() const
{
    return item_count_;
}  // end getCurrentSize

template<class T>
bool LinkedBag<T>::add(const T& new_entry)
{
   // Add to beginning of chain: new node references rest of chain;
   // (head_ptr_ is null if chain is empty)
   Node<T>* next_node_ptr = new Node<T>();
   next_node_ptr->setItem(new_entry);
   next_node_ptr->setNext(head_ptr_);  // New node points to chain
//   Node<T>* next_node_ptr = new Node<T>(new_entry, head_ptr_); // alternate code

   head_ptr_ = next_node_ptr;          // New node is now first node
   item_count_++;

   return true;
}  // end add


template<class T>
std::vector<T> LinkedBag<T>::toVector() const
{
   std::vector<T> bag_contents;
   Node<T>* cur_ptr = head_ptr_;
	while ((cur_ptr != nullptr))
   {
		bag_contents.push_back(cur_ptr->getItem());
        cur_ptr = cur_ptr->getNext();
   }  // end while

   return bag_contents;
}  // end toVector

template<class T>
bool LinkedBag<T>::remove(const T& an_entry)
{
   Node<T>* entry_node_ptr = getPointerTo(an_entry);
   bool can_remove = !isEmpty() && (entry_node_ptr != nullptr);
   if (can_remove)
   {
      // Copy data from first node to located node
      entry_node_ptr->setItem(head_ptr_->getItem());

      // Delete first node
      Node<T>* node_to_delete = head_ptr_;
      head_ptr_ = head_ptr_->getNext();

      // Return node to the system
      node_to_delete->setNext(nullptr);
      delete node_to_delete;
      node_to_delete = nullptr;

      item_count_--;
   } // end if

	return can_remove;
}  // end remove


template<class T>
void LinkedBag<T>::clear()
{
   Node<T>* node_to_delete = head_ptr_;
   while (head_ptr_ != nullptr)
   {
      head_ptr_ = head_ptr_->getNext();

      // Return node to the system
      node_to_delete->setNext(nullptr);
      delete node_to_delete;

      node_to_delete = head_ptr_;
   }  // end while
   // head_ptr_ is nullptr; node_to_delete is nullptr

	item_count_ = 0;
}  // end clear


template<class T>
int LinkedBag<T>::getFrequencyOf(const T& an_entry) const
{
	int frequency = 0;
   int counter = 0;
   Node<T>* cur_ptr = head_ptr_;
   while ((cur_ptr != nullptr) && (counter < item_count_))
   {
      if (an_entry == cur_ptr->getItem())
      {
         frequency++;
      } // end if

      counter++;
      cur_ptr = cur_ptr->getNext();
   } // end while

	return frequency;
}  // end getFrequencyOf

template<class T>
bool LinkedBag<T>::contains(const T& an_entry) const
{
	return (getPointerTo(an_entry) != nullptr);
}  // end contains




// private

/**
 @return Returns either a pointer to the node containing a given entry
 or the null pointer if the entry is not in the bag.
 */
template<class T>
Node<T>* LinkedBag<T>::getPointerTo(const T& an_entry) const
{
    bool found = false;
    Node<T>* cur_ptr = head_ptr_;

    while (!found && (cur_ptr != nullptr))
    {
        if (an_entry == cur_ptr->getItem())
            found = true;
        else
            cur_ptr = cur_ptr->getNext();
    } // end while

    return cur_ptr;
} // end getPointerTo




/**
   @param a_bag to be combined with the contents of this (the calling) bag
   @return a new LinkedBag that contains all elements from this
   bag (items_)and from a_bag. Note that it may contain duplicates
   */
  template<class T>
  LinkedBag<T> LinkedBag<T>::bagUnion(const LinkedBag<T>& a_bag) const
  {
    
 LinkedBag<T> Bag3;

Node<T>* temp_ptr = head_ptr_; //pointing to what the head pointer is pointing to in bag1


Node<T>* temp_ptr2 = a_bag.head_ptr_;

   while(temp_ptr2 != nullptr)
  {
   
    Bag3.add(temp_ptr2->getItem());
    temp_ptr2 = temp_ptr2->getNext();


  }
   
  while(temp_ptr != nullptr) 
    {
    
       Bag3.add(temp_ptr->getItem());
     

      temp_ptr = temp_ptr->getNext(); //traversing bag1

   }
//}
   return Bag3;
   } //end BagUnion


     /**
   @param a_bag to be intersected with the contents of this (the calling)
   bag
   @return a new LinkedBag that contains the intersection of the contents
   of this bag and those of the argument a_bag. This intersection does not
   contain duplicates (e.g. every element occurring in BOTH bags will be
   found only once in the intersection, no matter how many occurrences in
   the original bags) as in set intersection A ∩ B
   */
   template<class T>
   LinkedBag<T> LinkedBag<T>::bagIntersectionNoDuplicates(const LinkedBag<T>& a_bag) const
    {
      LinkedBag<T> test;
      test = bagUnion(a_bag);
   Node<T>* temp_1 = test.head_ptr_;


   LinkedBag<T> return_int;


   while(temp_1->getNext() != nullptr)
   {
   
    
      if((contains(temp_1->getItem()) && a_bag.contains(temp_1->getItem())) && !return_int.contains(temp_1->getItem()))
      {

        return_int.add(temp_1->getItem());
      }
  
    temp_1 = temp_1->getNext();
  

   }

   return return_int;

   }
   
   /**
   @param a_bag to be subtracted from this bag
   @return a new LinkedBag that contains only those items that occur in
   this bag or in a_bag but not in both, and it does not contain duplicates
   */
   template<class T>
   LinkedBag<T> LinkedBag<T>:: bagDifference(const LinkedBag<T>& a_bag) const
   {
    LinkedBag<T> test;
    test = bagUnion(a_bag);
    Node<T>* temp_1 = test.head_ptr_;
      LinkedBag<T> return_diff;



    while(temp_1 != nullptr)
    {
    
      if((contains(temp_1->getItem()) != a_bag.contains(temp_1->getItem()) ) && !return_diff.contains(temp_1->getItem())) //XOR
      {
        return_diff.add(temp_1->getItem());
      }
    temp_1 = temp_1->getNext();
  }

   


   
   return return_diff;

   }



  


    /**
   @param a_bag whose contents are to be copied to this (the calling) bag
   @post this (the calling) bag has same contents as a_bag
   */

  template<class T>
  void LinkedBag<T>::operator= (const LinkedBag<T>& a_bag)
  {
    clear();
     Node<T>* orig_chain_ptr = a_bag.head_ptr_;  // Points to nodes in original chain

     while(orig_chain_ptr != nullptr)
     {
      add(orig_chain_ptr->getItem());
      orig_chain_ptr = orig_chain_ptr->getNext();

     }

   
}  // end copy constructor



    /*
   @param new_entry to be added to the bag
   @post new_entry is added at the end of the chain preserving the order of
   items in the bag
   @return true if added successfully, false otherwise
   */
   
  template<class T>
   bool LinkedBag<T>::addToEnd(const T& new_entry)
  {
   Node<T>* cur_ptr;
   cur_ptr->setItem(new_entry);
    Node<T>* new_ptr; //needs to point to the last item in the node

   

    while(cur_ptr->getNext() != nullptr)
    {
      cur_ptr = cur_ptr->getNext();
    }

  
    new_ptr->setNext(cur_ptr);
    item_count_++;

    return true;

 } //end addToEnd 
// template<class T>
//    bool LinkedBag<T>::addToEnd(const T& new_entry)
//   {
    

//     Node<T>* new_node_ptr;
//     new_node_ptr->setItem(new_entry);
    
//     Node<T>* temp_ptr; //needs to point to the last item in the node

   

//     while(new_node_ptr->getNext() != nullptr)
//     {
//       new_node_ptr = new_node_ptr->getNext();
//     }

  
//     temp_ptr->setNext(new_node_ptr);
//     item_count_++;

//     return true;

//  } //end addToEnd 


  /**
 @param an_entry to be removed from the bag
 @post the first occurrence of an_entry starting from the head node is
 removed from the chain preserving the order of the remaining items in
 the bag
 @return true if removed successfully, false otherwise
 */
 template<class T>
 bool LinkedBag<T>::removeRetainOrder(const T& an_entry)
 {
  Node<T>* temp1 = head_ptr_;
  Node<T>* temp2;

  while(temp1 != nullptr && (temp1->getItem() != an_entry))
  {
    temp2 = temp1;
    temp1 = temp1->getNext();
  }
  if(temp1 == head_ptr_)
  {

    temp2 = temp1;
    head_ptr_ = temp1->getNext();
    temp1->setNext(nullptr);

  delete temp1;
  temp1 = nullptr;

  }
  else
  {
  temp2->setNext(temp1->getNext());
  temp1->setNext(nullptr);
  delete temp1;
  temp1 = nullptr;
}
  

  return true;

  //  Node<T>* entry_node_ptr = getPointerTo(an_entry);
  //  Node<T>* entry_node_ptr2 = 

  //  bool can_remove = !isEmpty() && (entry_node_ptr != nullptr);
  //  if (can_remove)
  //  {
  //     // Copy data from first node to located node
  //     entry_node_ptr->setItem(head_ptr_->getItem());

  //     // Delete first node
  //     Node<T>* node_to_delete = head_ptr_;
  //     head_ptr_ = head_ptr_->getNext();

  //     // Return node to the system
  //     node_to_delete->setNext(nullptr);
  //     delete node_to_delete;
  //     node_to_delete = nullptr;

  //     item_count_--;
  //  } // end if

  // return can_remove;




 }
 



    



 

 