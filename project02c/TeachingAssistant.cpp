/**
// @ file TeachingAssistant.cpp
// Project 1B
// 
// Created by Nick Szewczak on 1/31/19
// inherence from Student.hpp
*/ 

#include "TeachingAssistant.hpp"
#include <iostream>


TeachingAssistant::TeachingAssistant(int id, std::string first, std::string last):Student(id,first,last){
    role_ = LAB_ASSISTANT; //"You may assume for initialization purposes that the default role is LAB_ASSISTANT"
}

void TeachingAssistant::displayMember(){
    std::string time;
    if (getHours() > 8) time = "full-time";
    else time = "part-time";
    std::string role;
    if(getRole() == 0)role =     "LAB_ASSISTANT";
    if(getRole() == 1)role = "LECTURE_ASSISTANT";
    if(getRole() == 2)role =    "FULL_ASSISTANT";
    // Basnet Parakram majors in Computer Science with gpa: 1 working part-time as a LAB_ASSISTANT\n'
    std::cout << getFirstName() << " " << getLastName() << " majors in " << getMajor() << " with gpa: " << getGpa() << " working " << time << " as a " << role << "\n";
}


int TeachingAssistant::getHours() const{
    return hours_per_week_;
}

ta_role TeachingAssistant::getRole() const{
    return role_;
}

void TeachingAssistant::setHours(const int hours){
    hours_per_week_ = hours;
}

void TeachingAssistant::setRole(const ta_role role){
    role_ = role;
}