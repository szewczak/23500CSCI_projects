#include<iostream>
#include"LinkedList.hpp"

using namespace std;


int main (){
	//create a dummy list
	LinkedList<string>* myListPtr = new LinkedList<string>;
	for(int i=1; i<=10; i++){
		myListPtr->insert((myListPtr->getLength()+1), (to_string(i)));
	}


	//print said dummy list
	for(int i=1; i<=10; i++){
		cout << "nth object is " << myListPtr->getEntry(i) << endl;
	}
	
	return 0;
}