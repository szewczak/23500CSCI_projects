/*
	City for CSCI 23500 Hunter-CUNY. Project 04, Stack navigation of map.
	By Nick Szewczak (nickszewczak.com)
	template for readMap(), getCity(), isRoute() provided by Professor Tiziana Ligorio
*/

#include "City.hpp"
#include <string>
#include <vector>
#include <algorithm> 




/***************** Constructors ****************/
City::City(std::string CityName){
	city_node_ = CityName;
	visited = false;
	city_edges_.clear();
}

bool City::cityVisited() const{
	return visited;
}

std::string City::cityName() const{
	return city_node_;
}

std::vector<std::string> City::cityNeighbors(){
	return city_edges_;
}

bool City::addEdge(std::string const node){
	if(std::find(city_edges_.begin(),city_edges_.end(), node) != city_edges_.end()){
		/*city_edges_ contains node*/
		return false;
	}
	else{
		city_edges_.push_back(node);
		return true;
	}
}

// bool City::travelTo(std::vector<std::string> CityBlacklist, std::string* targetPtr){
// 	for(int i=0; i<city_edges_.size();i++){
// 		if(!(std::find(CityBlacklist.begin(), CityBlacklist.end(), city_edges_[i]) !=CityBlacklist.end())){
// 			/* CityBlacklist does not contain an Edge */
// 		}
// 	}
// /*
// for( unsigned int i = 0; i < m_VectorOfInts.size(); i++ )
// 			{
// 				std::cout << "Element[" << i << "] = " << m_VectorOfInts[i] << std::endl;
// 			}
// 			std::cout << std::endl;
// */
// }



	// LinkedList<T>::LinkedList() : head_ptr_(nullptr), item_count_(0){ // public function
	// }  // end default constructor