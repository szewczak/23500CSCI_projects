//  Modified by Nick Szewczak from assignment template, credit prof. Tiziana Ligorio


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

	void invert();
		// A  wrapper to a recursive method that inverts the contents of the list
		// @post the contents of the list are inverted such that
		//      the item previously at position 1 is at position item_count_,
		//      the item previously at position 2 is at position item_count_-1 ...
		//      the item previously at position ⌊item_count/2⌋ is at position ⌈item_count_/2⌉
	// tl;dr private wrapper

	void selectionSort();
		// A wrapper to a recursive selection sort method that sorts the list in increasing order
		// @post the contents of the list are sorted in increasing order such that
		// the item at position 1 <= the item at at position 2 <= ...
		// <= item at position item_count_-1
	// tl;dr private wrapper

	std::string LLstatus() const;


private:
	Node<T>* head_ptr_;
		// (contains the first entry in the list)
	// Pointer to first node in the chain;

	int item_count_;
	// Current count of list items

	Node<T>* getNodeAt(int position) const;
		// Locates a specified node in this linked list.
		// @pre  position is the number of the desired node;
		//       position >= 1 and position <= item_count_.
		// @post  The node is found and a pointer to it is returned.
		// @param position  The number of the node to locate.
		// @return  A pointer to the node at the given position.
	//tl;dr returns ptr to node x

	Node<T>* getNodeAtIndex(int index);
		// Locates a specified node in this linked list.
		// @pre  position is the number of the desired node;
		// @post  The node is found and a pointer to it is returned.
		// @param position  The number of the node to locate.
		// @return  A pointer to the node at the given index.
	//tl;dr returns ptr to node [index]

	/***************** PROJECT-SPECIFIC PRIVATE METHODS ****************/


	int minimumPosition(Node<T>* current_first_ptr);
	// index of the minimum item in LL
	
	Node<T>* recursiveSelectionSort(Node<T>* current_first_ptr);
		// recursive selection sort, used for safe programming to avoid
		// exposing pointers to list in public methods
		// To sort the list, it relies on re-linking the chain rather than copying data items
		// @post the contents of the list are sorted in increasing order such that
		// the item at position 1 <= the item at at position 2 <= ...
		// <= item at position item_count_-1
	//tl;dr a-z sort (recursive)

	void invertRest(Node<T>* current_first_ptr);														
}; // end LinkedList

#include "LinkedList.cpp"
#endif
