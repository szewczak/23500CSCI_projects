/**
// @ file CourseMember.cpp
// Project 1A
// 
// Created by Nick Szewczak on 1/31/19
*/ 
 

// #include <iostream>
#include "CourseMember.hpp"

CourseMember::CourseMember(int id, std::string first, std::string last){
    /* param id    the student's unique identifier
       param first the student's first name
       param last  the student's last name
    */
   id_ = id;
   first_name_ = first;
   last_name_ = last;
}

int CourseMember::getID() const{
    return id_;/** the CourseMember's ID */
}

std::string CourseMember::getFirstName() const{
    return first_name_;/** the CourseMember's first name */
}

std::string CourseMember::getLastName() const{
    return last_name_;/** the CourseMember's last name */
}


// int main(){
//     CourseMember Student(5,"nick","szewczak");
//     std::cout << Student.getFirstName() << std::endl
//          << Student.getLastName() << std::endl
//          << Student.getID() << std::endl;
//     return 0;
// }