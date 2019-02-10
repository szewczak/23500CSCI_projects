/**
// @file  TeachingAssistant.hpp
//  Project1B
//
//  Created by Nick Szewczak @ 20190209.
// - TeachingAssistant will be a derived class of Sttudent
*/

#ifndef TeachingAssistant_hpp
#define TeachingAssistant_hpp

#include <string>
#include "CourseMember.hpp"
#include "Student.hpp"

class TeachingAssistant: public Student
{
    enum ta_role {LAB_ASSISTANT, LECTURE_ASSISTANT, BOTH};
public:
    TeachingAssistant(int id, std::string first, std::string last);
    int getHours() const;
    ta_role _get_current_locale() const;
    void setHours(const int hours);
    void setRole(const ta_role role);
private:
    int hours_per_week_;
    ta_role role_;

};


#endif /*TeachingAssistant_hpp*/