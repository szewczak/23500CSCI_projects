//Nick Szewczak
//Bag Test.cpp
//CSC23500

#include "BagTest.hpp"



/**
 @pre the input file is in csv format as follows: “id,first_name,last_name,title\n”
 @post this function asks the user for an input file name. It extracts the information necessary to create a CourseMember object from each line in the input file, and it adds the corresponding CourseMember object to bag_.
 @return returns the populated bag_
 **/

ArrayBag<CourseMember> BagTest::testCourseMemberBag(){
    // std::cout << "yo gimme a .csv file name\n";
    // std::string filename;
    // std::cin >> filename;
    // return createBagFromInput(filename);
    return bag_;
}

/**
 @post prints to the standard output all CourseMeber objects found in bag_, one pre line if the format: id first_name last_name
 **/
void BagTest::displayCourseMemberBag(const ArrayBag<CourseMember>& a_bag){
    // std::vector<CourseMember> a_bag_vector = a_bag.toVector();
    // for(int i=0; i< a_bag.getCurrentSize(); i++){
    //     // std::cout << a_bag_vector[i].getID() << " " << a_bag_vector[i].getFirstName() << " " << a_bag_vector[i].getLastName() << std::endl; 
    // }
} 

/**
 @post asks the user for a last name and removes ONE CourseMember with that last name if it finds one
 @return returns the bag_ after removal
 **/
ArrayBag <CourseMember> BagTest::removeCourseMemberFromBag(){
    // std::string member;
    // std::cout << "yo tell me a name";
    // std:: cin >> member;
    // ArrayBag<CourseMember> stub;
    // return stub;
    return bag_;
}

ArrayBag <CourseMember> BagTest::removeCourseMemberFromBag(const CourseMember& member){
    // ArrayBag<CourseMember> stub;
    // return stub;
    return bag_;
}

ArrayBag <CourseMember> BagTest::createBagFromInput(std::string input_file){
    // std::ifstream fin(input_file);
    // int id;
    // std::string fname;
    // std::string lname;

    // while(fin >> id >> fname >> lname){
    //     CourseMember cuny(id, fname, lname);
    //     bag_.add(cuny);
    // }
    return bag_;

}