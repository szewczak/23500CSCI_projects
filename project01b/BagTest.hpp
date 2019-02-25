#ifndef Bag_Test_
#define Bag_Test_

#include "CourseMember.hpp"
#include "ArrayBag.hpp"
#include <fstream>
#include <iostream>


class BagTest{
private:
ArrayBag<CourseMember> bag_; 
// ArrayBag <CourseMember> createBagFromInput(std::string input_file);

public:

BagTest();

/**
 @pre the input file is in csv format as follows: “id,first_name,last_name,title\n”
 @post this function asks the user for an input file name. It extracts the information necessary to create a CourseMember object from each line in the input file, and it adds the corresponding CourseMember object to bag_.
 @return returns the populated bag_
 **/
ArrayBag <CourseMember> testCourseMemberBag();

/**
 @post prints to the standard output all CourseMeber objects found in bag_, one pre line if the format: id first_name last_name
 **/
void displayCourseMemberBag(const ArrayBag<CourseMember>& a_bag); 

/**
 @post asks the user for a last name and removes ONE CourseMember with that last name if it finds one
 @return returns the bag_ after removal
 **/
ArrayBag <CourseMember> removeCourseMemberFromBag();

/**
 @param member to be removed from bag_
 @post removes one occurrence of member if found in bag_
 @return returns the bag_ after removal if any
 **/
ArrayBag <CourseMember> removeCourseMemberFromBag(const CourseMember& member);

};

//#include "BagTest.cpp"
#endif
