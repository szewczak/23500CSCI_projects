#include<iostream>
#include"LinkedList.hpp"

using namespace std;


int main (){
	//create a dummy list
	LinkedList<int>* myListPtr = new LinkedList<int>;
	
	// for(int i=1; i<=10; i++){
	// 	myListPtr->insert((myListPtr->getLength()+1), i);
	// }


	myListPtr->insert((myListPtr->getLength()+1), 5);
	myListPtr->insert((myListPtr->getLength()+1), 2);
	myListPtr->insert((myListPtr->getLength()+1), 6);
	myListPtr->insert((myListPtr->getLength()+1), 4);
	myListPtr->insert((myListPtr->getLength()+1), 0);
	myListPtr->insert((myListPtr->getLength()+1), 3);
	myListPtr->insert((myListPtr->getLength()+1), 1);

	// myListPtr->insert((myListPtr->getLength()+1), 0);
	// myListPtr->insert((myListPtr->getLength()+1), 1);
	// myListPtr->insert((myListPtr->getLength()+1), 2);
	// myListPtr->insert((myListPtr->getLength()+1), 3);
	// myListPtr->insert((myListPtr->getLength()+1), 4);
	// myListPtr->insert((myListPtr->getLength()+1), 5);
	// myListPtr->insert((myListPtr->getLength()+1), 6);



	cout << endl << "LinkedList contains: ";
	for(int i=0; i<myListPtr->getLength(); i++){
 		cout << myListPtr->getEntry(i+1) << ", ";
	}

	cout << (myListPtr->LLstatus()) << endl;
	cout << endl << "~~~~~~~~~~~~~~~~" << endl << endl;

	cout << "\t calling sort()\n";
	// cout << "that item is " << myListPtr->

	myListPtr->selectionSort();


	//print said dummy list
	for(int i=0; i<myListPtr->getLength(); i++){
		cout << "nth object is " << myListPtr->getEntry(i+1) << endl;
	}
	myListPtr->getLength();

	return 0;
}