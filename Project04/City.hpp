/*
	City for CSCI 23500 Hunter-CUNY. Project 04, Stack navigation of map.
	By Nick Szewczak (nickszewczak.com)
	template for readMap(), getCity(), isRoute() provided by Professor Tiziana Ligorio
*/

#ifndef City_
#define City_
#include <string>
#include <vector>

class City
{
  public:
	/***************** Constructors ****************/
	City(std::string CityName);
	// named node constructor

	/***************** Accessors ****************/
	bool cityVisited() const;
	// visited accessor

	std::string getCityName() const;
	// city_node_ accessor

	std::string getCityEdges() const;
	// city_node_ accessor

	std::vector<std::string> cityNeighbors();
	// copy of city_edges_ vector

	/***************** Kitchen Sink ****************/
	bool addEdge(std::string const node);
	// add an edge connecting this node to other nodes.
	// If connection already exists RETURN False.

	// bool travelTo(std::vector<std::string> CityBlacklist, std::string* targetPtr);
	 // 	// finds next city to travel to. Returns True if there is an option.
	 // 	// if city_edges_ contains an element NOT on CityBlacklist,
	 // 	// targetPtr is updated with that city name

  private:
	std::string city_node_;
	// Top Level ID for this city
	bool visited;
	// memory for if this city has been traveled to previously.

	std::vector<std::string> city_edges_;
	// Vector of city_nodes; that this object has access to.
	// note std vectors from <vector> self destruct naturally
};

#include "City.cpp"
#endif
