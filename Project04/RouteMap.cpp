/*
	City for CSCI 23500 Hunter-CUNY. Project 04, Stack navigation of map.
	By Nick Szewczak (nickszewczak.com)
	template for readMap(), getCity(), isRoute() provided by Professor Tiziana Ligorio
*/

#include"RouteMap.hpp"
#include<string>
#include<vector>
#include <fstream>


myRouteMap::myRouteMap(std::string csvName){
	std::fstream csv_file;
	csv_file.open(csvName);
	std::string temp;
	std::string dash = "-";
	while(std::getline(csv_file,temp, ',')){
		if(temp.length() != 0){	// ignore empty cells
			size_t isRoute = temp.find(dash); 
			if (isRoute == std::string::npos){
				// this is a new city designator
				// add city to cities_
				cities_.push_back(City(temp));
			} 
			else{
				// this is a new path designtor
				// find city in cities_ and add path
				City* this_city;
			}
		}
	}
}