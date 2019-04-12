//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.
//
//  added Project3A specific methods
//  Modified by Nick Szewczak for Hunter College CSCI 235 for assignment
//
//  How my recusiveSelectionSort() works:
//  	Minimum node is found by minimumPosition() and reported as an ofsset-index
//  	from current_first_ptr. Edge cases for an empty list and first item being min
//		are handled.
//		Otherwise minimum item is moved to front of list, and recusiveSelectionSort() is
//		is called on head_ptr_->getNext()

/** ADT list: Singly linked list implementation.

 Implementation file for the class LinkedList.
 @file LinkedList.cpp */

#include "LinkedList.hpp"  // Header file
#include <cassert>
// #include <iostream>

/***************** PROJECT-TEMPLATE DERIVED ****************/
	template<class T>
	LinkedList<T>::LinkedList() : head_ptr_(nullptr), item_count_(0){ // public function
	}  // end default constructor

	template<class T>
	LinkedList<T>::LinkedList(const LinkedList<T>& a_list) : item_count_(a_list.item_count_)
	{
		Node<T>* orig_chain_pointer = a_list.head_ptr_;  // Points to nodes in original chain

		if (orig_chain_pointer == nullptr)
		head_ptr_ = nullptr;  // Original list is empty
		else
		{
		// Copy first node
		head_ptr_ = new Node<T>();
		head_ptr_->setItem(orig_chain_pointer->getItem());

		// Copy remaining nodes
		Node<T>* new_chain_ptr = head_ptr_;		// Points to last node in new chain
		orig_chain_pointer = orig_chain_pointer->getNext();	  // Advance original-chain pointer
		while (orig_chain_pointer != nullptr)
		{
			// Get next item from original chain
			T next_item = orig_chain_pointer->getItem();

			// Create a new node containing the next item
			Node<T>* new_node_ptr = new Node<T>(next_item);

			// Link new node to end of new chain
			new_chain_ptr->setNext(new_node_ptr);

			// Advance pointer to new last node
			new_chain_ptr = new_chain_ptr->getNext();

			// Advance original-chain pointer
			orig_chain_pointer = orig_chain_pointer->getNext();
		}  // end while

		new_chain_ptr->setNext(nullptr);				  // Flag end of chain
		}  // end if
	}  // end copy constructor

	template<class T>
	LinkedList<T>::~LinkedList()
	{
		clear();
	}  // end destructor

	template<class T>
	bool LinkedList<T>::isEmpty() const{ // public function
		return item_count_ == 0;
	}  // end isEmpty

	template<class T>
	int LinkedList<T>::getLength() const{ // public function
		return item_count_;
	}  // end getLength

	template<class T>
	bool LinkedList<T>::insert(int new_position, const T& new_entry){ // public function
		bool able_to_insert = (new_position >= 1) && (new_position <= item_count_ + 1);
		if (able_to_insert)
		{
		// Create a new node containing the new entry
		Node<T>* new_node_ptr = new Node<T>(new_entry);

		// Attach new node to chain
		if (new_position == 1)
		{
			// Insert new node at beginning of chain
			new_node_ptr->setNext(head_ptr_);
			head_ptr_ = new_node_ptr;
		}
		else
		{
			// Find node that will be before new node
			Node<T>* prev_ptr = getNodeAt(new_position - 1);

			// Insert new node after node to which prev_ptr points
			new_node_ptr->setNext(prev_ptr->getNext());
			prev_ptr->setNext(new_node_ptr);
		}  // end if

		item_count_++;  // Increase count of entries
		}  // end if

		return able_to_insert;
	}  // end insert

	template<class T>
	bool LinkedList<T>::remove(int position){ // public function
		bool able_to_remove = (position >= 1) && (position <= item_count_);
		if (able_to_remove)
		{
		Node<T>* cur_ptr = nullptr;
		if (position == 1)
		{
			// Remove the first node in the chain
			cur_ptr = head_ptr_; // Save pointer to node
			head_ptr_ = head_ptr_->getNext();
		}
		else
		{
			// Find node that is before the one to delete
			Node<T>* prev_ptr = getNodeAt(position - 1);

			// Point to node to delete
			cur_ptr = prev_ptr->getNext();

			// Disconnect indicated node from chain by connecting the
			// prior node with the one after
			prev_ptr->setNext(cur_ptr->getNext());
		}  // end if

		// Return node to system
		cur_ptr->setNext(nullptr);
		delete cur_ptr;
		cur_ptr = nullptr;

		item_count_--;  // Decrease count of entries
		}  // end if

		return able_to_remove;
	}  // end remove

	template<class T>
	void LinkedList<T>::clear(){ // public function
		while (!isEmpty())
		remove(1);
	}  // end clear

	template<class T>
	T LinkedList<T>::getEntry(int position) const{ // public function
		T dummy;
		// Check precondition
		bool able_to_get = (position >= 1) && (position <= item_count_);
		if (able_to_get)
		{
		Node<T>* nodePtr = getNodeAt(position);
		return nodePtr->getItem();
		}
		else
			return dummy; //PROBLEM!!!! may return uninitialized object - will fix later with Exception Handling

	}  // end getEntry


	template<class T>
	void LinkedList<T>::invert(){ // public function
		if(!(head_ptr_==nullptr)){
			Node<T>* m = head_ptr_;
			invertRest(head_ptr_);
			m->setNext(nullptr);
		}
	}

	template<class T>
	Node<T>* LinkedList<T>::getNodeAt(int position) const{ // private function
		//recursively inverts the contents of he list, used for safe programming to avoid
		//exposing pointers to list in public methods
		// @post the contents of the list are inverted such that
		//		the item previously at position 1 is at position item_count_,
		//		the item previously at position 2 is at position item_count_-1 ...
		//		the item previously at position âŒŠitem_count/2âŒ‹ is at position âŒˆitem_count_/2âŒ‰
		// Debugging check of precondition
		assert( (position >= 1) && (position <= item_count_) );

		// Count from the beginning of the chain
		Node<T>* cur_ptr = head_ptr_;
		for (int skip = 1; skip < position; skip++)
		cur_ptr = cur_ptr->getNext();
		return cur_ptr;
	}  // end getNodeAt



/***************** PROJECT-SPECIFIC METHODS ****************/

template<class T>
std::string LinkedList<T>::LLstatus() const{	// DEBUGGING tool Unused in final recursive sort implmnt.
	std::string out = "Item count: ";
	out = out + std::to_string(item_count_);
	if(head_ptr_ == nullptr){
		out = out + " and head_ptr_ is currently a nullptr";
	}
	else{
		out = out + " and head_ptr_ is currently pointed at: ";
		out = out + std::to_string(head_ptr_->getItem());
	}
	return out;
}

template<class T>
Node<T>* LinkedList<T>::getNodeAtIndex(int index){
	// std::cout << "getNodeAtIndex::requesting ptr to node[" << index << "]" << std::endl;
	Node<T>* nth_node = head_ptr_;
	for(int i=0; i < index; i++){
		nth_node = nth_node->getNext();
	}
	// std::cout << "getNodeAtIndex::" << index << "th node is " << nth_node->getItem() << std::endl;
	return nth_node;
}

// template<class T>
// int LinkedList<T>::minimum(){ // public function
// 	return minimumPosition();
// }


template<class T>
void LinkedList<T>::invertRest(Node<T>* current_first_ptr){ // private function
	if(current_first_ptr->getNext() == nullptr){							// IF the next node doesn't exist, this is the last node
		head_ptr_ = current_first_ptr;										// set the head pointer to this last object, AND DO NOT RECURSE AGAIN
	}
	else{
		invertRest(current_first_ptr->getNext());
		current_first_ptr->getNext()->setNext(current_first_ptr);			// 
	}
}

template<class T>
int LinkedList<T>::minimumPosition(Node<T>* current_first_ptr){ // private function
	int minIndex = 0;
	if(current_first_ptr == nullptr){
		return 0;
	}
	Node<T>* itrPointer = current_first_ptr;
	Node<T> minTemp = head_ptr_->getItem();
	int i = 0;
	while(!(itrPointer == nullptr)){
		// std::cout << i << "minimumPosition:: comparing " << minTemp.getItem() << " <= " << itrPointer->getItem() << std::endl;
		if(minTemp.getItem() > itrPointer->getItem()){
			minTemp = *itrPointer;
			minIndex = i;
		}
		itrPointer = itrPointer->getNext();
		i++;
	}
	return minIndex;
}

template<class T>
void LinkedList<T>::selectionSort(){ // public function
	if(!(head_ptr_==nullptr)){
		recursiveSelectionSort(head_ptr_);
	}
}

template<class T>
Node<T>* LinkedList<T>::recursiveSelectionSort(Node<T>* current_first_ptr){ // private function
	if(current_first_ptr == nullptr){
		// std::cout << std::endl << "\trSS:: called on empty list" << std::endl;
		return nullptr;
	}
	// std::cout << std::endl << "\trSS:: called on normal list:" << std::endl;
	int minIndex = minimumPosition(current_first_ptr);
	// std::cout << std::endl << "\tmin index is " << minIndex << std::endl;
	Node<T>* minPtr = nullptr;
	if(minIndex == 0){
		minPtr = current_first_ptr;
		current_first_ptr = current_first_ptr->getNext();
	}
	else{
		Node<T>* beforeMinPtr = current_first_ptr;
		for(int i=0; i<minIndex-1;i++){
			beforeMinPtr = beforeMinPtr->getNext();
		}													// beforeMinPtr = min-1 ptr
		minPtr = beforeMinPtr->getNext();
		beforeMinPtr->setNext((minPtr->getNext()));			// minPtr now removed from list
	}														// minPtr removed from all cases of list (item_count_ not changed!)
	minPtr->setNext(recursiveSelectionSort(current_first_ptr));
	head_ptr_ = minPtr;
	
	return minPtr;
}


/*

Node<T>* 

*/

//  End of implementation file.