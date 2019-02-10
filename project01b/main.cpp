/**
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

#include <iostream>
#include "CourseMember.hpp"
#include "Student.hpp"
#include "Instructor.hpp"
#include "TeachingAssistant.hpp"
using namespace std;

int main(){
    CourseMember nsz(5,"nick","szewczak");
    cout << nsz.getFirstName() << endl;
    cout << nsz.getLastName() << endl;
    cout << nsz.getID() << endl;
    coud << nsz.getGPA()

    Student jimmy(6,"Jimmy","Jerkface");
    cout << jimmy.getFirstName() << endl;
    cout << jimmy.getLastName() << endl;
    cout << jimmy.getID() << endl;
    
    Instructor Tommala(6,"Tommala","Professor");
    cout << Tommala.getFirstName() << endl;
    cout << Tommala.getLastName() << endl;
    cout << Tommala.getID() << endl;
    
    TeachingAssistant Edberg(6,"Edberg","TA");
    cout << Edberg.getFirstName() << endl;
    cout << Edberg.getLastName() << endl;
    cout << Edberg.getID() << endl;

    return 0;
}