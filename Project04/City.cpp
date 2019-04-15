/*
	City for CSCI 23500 Hunter-CUNY. Project 04, Stack navigation of map.
	By Nick Szewczak (nickszewczak.com)
	template for readMap(), getCity(), isRoute() provided by Professor Tiziana Ligorio
*/

#include "City.hpp"
#include <string>
#include <vector>
#include <algorithm> 

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
