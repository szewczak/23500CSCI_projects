/*
	City for CSCI 23500 Hunter-CUNY. Project 04, Stack navigation of map.
	By Nick Szewczak (nickszewczak.com)
	template for readMap(), getCity(), isRoute() provided by Professor Tiziana Ligorio
*/

#ifndef RouteMap_
#define RouteMap_
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include "City.hpp"

class myRouteMap
{
  public:
	/***************** Constructors ****************/
	myRouteMap(std::string csvName);
	
	/***************** Accessors ****************/
	/**
	 @return a pointer to the city found at position, where
	 0 <= position <= n-1, and n is the number of cities,
	 and cities are stored in the same order in which they appear
	 in the input file
	 **/
	City* getCity(int position);
	void  allCitiesOut();
	
  private:
	std::vector<City> cities_;
	/***************** Kitchen Sink ****************/
	City* getCityByName(std::string name);
	void evaluateCsvCell(std::string cell);
	// Vector of city_nodes; that this object has access to.
	// note std vectors from <vector> self destruct naturally
};

#include "RouteMap.cpp"
#endif
