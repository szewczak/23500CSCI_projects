/*
	City for CSCI 23500 Hunter-CUNY. Project 04, Stack navigation of map.
	By Nick Szewczak (nickszewczak.com)
	template for readMap(), getCity(), isRoute() provided by Professor Tiziana Ligorio
*/

#include "RouteMap.hpp"
#include "City.hpp"

myRouteMap::myRouteMap(std::string csvName)
{
	std::fstream csv_file;
	csv_file.open(csvName);
	std::string temp;
	std::string dash = "-";
	while (std::getline(csv_file, temp))
	{ // read line to temp
		if ((temp.substr((temp.length() - 1), 1)) == "\r")
		{ //
			temp = temp.substr(0, temp.length() - 1);
		}
		if ((temp.substr((temp.length() - 1), 1)) == "\n")
		{
			temp = temp.substr(0, temp.length() - 1);
		}
		// std::cout << "last character: `" << temp.substr((temp.length()-1),1) << "`..." << std::endl;
		std::istringstream linestream(temp);
		while (std::getline(linestream, temp, ','))
		{
			if (temp.length() != 0)
			{ // ignore empty cells
				// std::cout << "\tthis cell is `" << temp << "`" << std::endl;
				evaluateCsvCell(temp);
			}
		}
	}
}

void myRouteMap::allCitiesOut()
{
	std::cout << "cities currently in cities_:" << std::endl;
	for (int i = 0; i < cities_.size(); i++)
	{
		std::cout << cities_[i].getCityName() << "\t" << cities_[i].getCityEdges() << std::endl;
	}
}

City *myRouteMap::getCityByName(std::string name)
{
	// std::cout << "\t\tgetCityByName(" << name << ")" << std::endl;
	for (int i = 0; i < cities_.size(); i++)
	{
		if (name == cities_[i].getCityName())
		{
			// this is the index of the city we are looking for
			return &(cities_[i]);
		}
	}
	return nullptr;
}

void myRouteMap::evaluateCsvCell(std::string cell)
{
	// std::cout << "evaluateCsvCell(" << cell << ")" << std::endl;
	size_t dashPos = cell.find("-");
	if (dashPos == std::string::npos)
	{
		// this is a new city designator
		// add city to cities_
		cities_.push_back(City(cell));
	}
	else
	{
		// std::cout << "new path: `" << cell << "`" << std::endl;
		City *targetPtr = getCityByName(cell.substr(0, dashPos));
		targetPtr->addEdge(cell);
	}
}

City *myRouteMap::getCity(int position)
{
	return &(cities_[position]);
}
