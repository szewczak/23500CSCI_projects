/**
// @ file Student.cpp
// Project 1B
// 
// Created by Nick Szewczak on 1/31/19
// inherence from CourseMember.hpp
*/ 

#include "Student.hpp"
#include <iostream>

Student::Student(int id, std::string first, std::string last):CourseMember(id,first,last){}

std::string Student::getMajor() const{
    return major_;
}

void Student::displayMember(){
    std::cout << getFirstName() << " " << getLastName() << " majors in " << getMajor() << " with gpa: " << getGpa() << "\n";
}

double Student::getGpa() const{
    return gpa_;
}

void Student::setMajor(const std::string major){
    major_ = major;
}

void Student::setGpa(const double gpa){
    gpa_ = gpa;
}