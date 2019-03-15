/**
// @ file Instructor.cpp
// Project 1B
// 
// Created by Nick Szewczak on 1/31/19
// inherence from CourseMember.hpp
*/ 

#include "Instructor.hpp"
#include <iostream>

Instructor::Instructor(int id, std::string first, std::string last):CourseMember(id,first,last){}

void Instructor::displayMember(){
    std::cout << getFirstName() << " " << getLastName() << " - office: " << getOffice() << ", email: " << getContact() << "\n";
}

std::string Instructor::getOffice() const{
    return office_;
}

std::string Instructor::getContact() const{
    return contact_;
}

void Instructor::setOffice(const std::string office){
    office_ = office;
}

void Instructor::setContact(const std::string contact){
    contact_ = contact;
}
