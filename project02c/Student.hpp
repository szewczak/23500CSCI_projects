/**
// @file  Student.hpp
//  Project1B
//
//  Created by Nick Szewczak @ 20190209.
//  Derived class of CourseMember.hpp
*/

#ifndef Student_hpp
#define Student_hpp

#include <string>
#include "CourseMember.hpp"

class Student: public CourseMember
{
public:
    Student(int id, std::string first, std::string last);
    std::string getMajor() const;
    double getGpa() const;
    void setMajor(const std::string major);
    void setGpa(const double gpa);
    
protected:
    std::string major_;
    double gpa_;
};


#endif /*Student_hpp*/