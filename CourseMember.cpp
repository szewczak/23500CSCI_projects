/**
// @ file CourseMember.cpp
// Project 1B
// 
// Created by Nick Szewczak on 1/31/19
// Part B of Project1 will let you practice a bit more with writing simple classes and
// become accustomed to working with multiple classes and multiple source files, while
// applying the new concept of Inheritance.
// 
// In part A you wrote the !!CourseMember!! !class!. Every CourseMember has a first
// name, last name and ID by which they can be identified. Everyone in this course is a
// CurseMember, however there are different *roles* a CourseMember may take. We
// have Students, TeachingAssistants and Instructors. These are all CourseMembers
// (with a first name, last name and ID), but they also have other attributes specific to
// their role.
// For part B of Project1 you will write !!3 classes!!:
// - Student
// - TeachingAssistant
// - Instructor
// Both Students and Instructors are CourseMembers. A TeachingAssistant is not only a
// CourseMember but also a Student. Thus the !!inheritance structure!! will be as follows:
// - Student will be a derived class of CourseMember
// - TeachingAssistant will be a derived class of Student
// - Instructor will be a derived class of CourseMember
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