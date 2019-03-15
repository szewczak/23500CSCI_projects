#include <vector>
#include <iostream>
#include "CourseMember.hpp"
#include "Student.hpp"
#include "TeachingAssistant.hpp"
#include "Instructor.hpp"
// imran

using namespace std;


int main(){
    CourseMember* genPointer;

    Student* cat = new Student(01,"Mr.", "Fluffy");
    // cat->setGpa(3.2);
    // cat->setMajor("scowling");
    // cat.displayMember();
    genPointer = cat;
    genPointer->displayMember();
    delete genPointer;
    genPointer = nullptr;
    
    TeachingAssistant* dog = new TeachingAssistant(02, "Good", "Doggy");
    // dog->setGpa(4.0);
    // dog->setMajor("Branch_Managment");
    // dog->setRole(BOTH);
    // dog->displayMember();
    genPointer = dog;
    genPointer->displayMember();
    delete genPointer;
    genPointer = nullptr;

    Instructor* wolf = new Instructor(03, "lady", "Wolf");
    // wolf->setContact("badWolf@dr.who");
    // wolf->setOffice("HN 443");
    // wolf->displayMember();
    genPointer = wolf;
    genPointer->displayMember();
    delete genPointer;
    genPointer = nullptr;

    return 0;
}