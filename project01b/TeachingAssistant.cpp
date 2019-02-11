/**
// @ file TeachingAssistant.cpp
// Project 1B
// 
// Created by Nick Szewczak on 1/31/19
// inherence from Student.hpp
*/ 

#include "TeachingAssistant.hpp"

TeachingAssistant::TeachingAssistant(int id, std::string first, std::string last):Student(id,first,last){
    role_ = LAB_ASSISTANT; //"You may assume for initialization purposes that the default role is LAB_ASSISTANT"
}

int TeachingAssistant::getHours() const{
    return hours_per_week_;
}

TeachingAssistant::ta_role TeachingAssistant::getRole() const{
    return role_;
}

void TeachingAssistant::setHours(const int hours){
    hours_per_week_ = hours;
}

void TeachingAssistant::setRole(const ta_role role){
    role_ = role;
}