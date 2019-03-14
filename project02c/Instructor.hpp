/**
// @file  Instructor.hpp
//  Project1B
//
//  Created by Nick Szewczak @ 20190209.
// - Instructor will be a derived class of CourseMember
*/

#ifndef Instructor_hpp
#define Instructor_hpp

#include <string>
#include "CourseMember.hpp"

class Instructor: public CourseMember
{
public:
    Instructor(int id, std::string first, std::string last);
    void displayMember() const;
    std::string getOffice() const;
    std::string getContact() const;
    void setOffice(const std::string office);
    void setContact(const std::string contact);
private:
    std::string office_;
    std::string contact_;
};


#endif /*Instructor_hpp*/