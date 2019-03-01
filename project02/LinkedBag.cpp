//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.
//  Modified by Tiziana Ligorio 2019 for CSCI 235 Hunter College
/** ADT bag: Link-based implementation.
    @file LinkedBag.cpp */
#include "LinkedBag.hpp"
#include "Node.hpp"
#include <cstddef>
// #include <iostream>
template<class T>
LinkedBag<T>::LinkedBag() : head_ptr_(nullptr), item_count_(0){
}  // end default constructor

template<class T>
LinkedBag<T>::LinkedBag(const LinkedBag<T>& a_bag){
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
LinkedBag<T>::~LinkedBag(){
   clear();
}  // end destructor

template<class T>
bool LinkedBag<T>::isEmpty() const{
	return item_count_ == 0;
}  // end isEmpty

template<class T>
int LinkedBag<T>::getCurrentSize() const{
    return item_count_;
}  // end getCurrentSize

template<class T>
bool LinkedBag<T>::add(const T& new_entry){
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
std::vector<T> LinkedBag<T>::toVector() const{
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
bool LinkedBag<T>::remove(const T& an_entry){
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
void LinkedBag<T>::clear(){
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
int LinkedBag<T>::getFrequencyOf(const T& an_entry) const{
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
bool LinkedBag<T>::contains(const T& an_entry) const{
	return (getPointerTo(an_entry) != nullptr);
}  // end contains


template<class T>
LinkedBag<T> LinkedBag<T>::bagUnion(const LinkedBag<T>& a_bag) const{
   //@param a_bag to be combined with the contents of this (the calling) bag
   //@return a new LinkedBag that contains all elements from this bag (items_)and from a_bag. Note that it may contain duplicates
   LinkedBag<T> b_bag(a_bag);          // return bag. Add a_bag to it on creation
   Node<T>* cur_ptr = head_ptr_;       // keeping track of currnet THIS.ptr

   while(cur_ptr != nullptr){          // loop through all items in THIS bag
      b_bag.add(cur_ptr->getItem());             // add node to b_bag
      cur_ptr = cur_ptr->getNext();    // move current ptr forward
   }
   return b_bag;
}

template<class T>
LinkedBag<T> LinkedBag<T>::bagIntersectionNoDuplicates(const LinkedBag<T>& a_bag)const{
   LinkedBag<T> b_bag;          // return bag. Add a_bag to it on creation
   b_bag = bagUnion(a_bag);
   Node<T>* b_ptr = b_bag.head_ptr_;   // keeping track of currnet THIS.ptr
   LinkedBag<T> c_bag;                 // return bag

   while(b_ptr != nullptr){
      if(  (contains(b_ptr->getItem() )  &&  a_bag.contains(b_ptr->getItem() )   )   &&  !c_bag.contains(b_ptr->getItem() ) ){
         c_bag.add(b_ptr->getItem() );
      }
      b_ptr = b_ptr->getNext();
   }
   
   return c_bag;
}

template<class T>
LinkedBag<T> LinkedBag<T>::bagDifference(const LinkedBag<T>& a_bag) const{
   LinkedBag<T> b_bag;                 // temp bag
   b_bag = bagUnion(a_bag);            // dump of all bags
   Node<T>* b_ptr = b_bag.head_ptr_;   // keeping track of currnet THIS.ptr
   LinkedBag<T> c_bag;                 // return bag

   while(b_ptr != nullptr){            // traversing b_bag, the union of caller bag and a_bag
      // std::cout << "\t" <<  b_ptr->getItem() << std::endl;
      if(  (contains(b_ptr->getItem()) != a_bag.contains(b_ptr->getItem()) )  &&   !c_bag.contains(b_ptr->getItem())    ){
               // std::cout << "\t\t UNIQUE: " <<  b_ptr->getItem() << std::endl;
         c_bag.add(b_ptr->getItem());
      }
      b_ptr = b_ptr->getNext();
   }
   return c_bag;
}

template<class T>
void LinkedBag<T>::operator= (const LinkedBag<T>& a_bag){
   clear();
   std::vector<T> bag_contents = a_bag.toVector();
   for(int i=0; i < a_bag.getCurrentSize(); i++){
      add(bag_contents[i]);
   }
}

template<class T>
bool LinkedBag<T>::addToEnd(const T& new_entry){
   Node<T>* cur_ptr = head_ptr_;
   // Node<T>* prv_ptr = head_ptr_;
   Node<T>* last_node_ptr = new Node<T>();
   last_node_ptr->setItem(new_entry);
   last_node_ptr->setNext(nullptr);

   while(cur_ptr->getNext() !=nullptr){
      // prv_ptr = cur_ptr;
      cur_ptr = cur_ptr->getNext();
   }

   cur_ptr->setNext(last_node_ptr);

   item_count_++;

   return true;
}
    


template<class T>
bool LinkedBag<T>::removeRetainOrder(const T& an_entry){
    Node<T>* cur_ptr = head_ptr_;
    Node<T>* prv_ptr = head_ptr_;
    Node<T>* tmp_ptr = nullptr;
    
    if((cur_ptr->getItem() == an_entry) && (cur_ptr == head_ptr_)){
       tmp_ptr = cur_ptr->getNext();         // two line step for clarity
       head_ptr_ = tmp_ptr;
       delete cur_ptr;
       item_count_--;
       cur_ptr = nullptr;
       prv_ptr = nullptr;
       tmp_ptr = nullptr;
       return true;
    }
    while(cur_ptr != nullptr){
       if(cur_ptr->getItem() == an_entry){
          tmp_ptr = cur_ptr->getNext();         // two line step for clarity
          prv_ptr->setNext(tmp_ptr);            // previous element now points to next elment
          delete cur_ptr;
          cur_ptr = nullptr;
          prv_ptr = nullptr;
          tmp_ptr = nullptr;
          item_count_--;
          return true;                           // we don't need to keep managing ptrs anymore. we are done
       }
       prv_ptr = cur_ptr;                        // retain prev ptr
       cur_ptr = cur_ptr->getNext();             // move current ptr forward
    }
    cur_ptr = nullptr;
    prv_ptr = nullptr;
    tmp_ptr = nullptr;
    return false;
}

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
