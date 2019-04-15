/*
	CSCI 23500 Hunter-CUNY. Project 04, Stack navigation of map.
	By Nick Szewczak (nickszewczak.com)
*/

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <iostream>
#include "City.hpp"
#include "RouteMap.hpp"

using namespace std;

int main()
{
	// cout << "test" << endl;
	// City bar("nyc");
	// bar.addEdge("dc");
	// bar.addEdge("hell");
	// vector<string> nearby = bar.cityNeighbors();
	// for (int i = 0; i < nearby.size(); i++)
	// {
	// 	cout << nearby[i] << endl;
	// }
	myRouteMap foo("linuxonly.csv");
	cout << endl;
	foo.allCitiesOut();
	return 0;
}