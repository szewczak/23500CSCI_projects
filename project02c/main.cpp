#include <vector>
#include <iostream>
#include "CourseMember.hpp"
#include "Student.hpp"
#include "TeachingAssistant.hpp"
#include "Instructor.hpp"
#include "polytest.hpp"
#include "List.hpp"
#include "Node.hpp"
// imran

using namespace std;


int main(){
    List<CourseMember*> cm_list;
    populateCmList(cm_list, "roster.csv");
    for(int i=0; i<cm_list.getLength();i++){
        cm_list.getItem(i)->displayMember();
    }

    // addMemberToList(cm_list, 22, "cat", "Meower", "Student");
    // Student* cat = new Student(01,"Mr.", "Fluffy");
    // cat->setGpa(3.2);
    // cat->setMajor("scowling");
    // genPointer = cat;
    // genPointer->displayMember();
    // delete genPointer;
    // genPointer = nullptr;
    
    // TeachingAssistant* dog = new TeachingAssistant(02, "Good", "Doggy");
    // dog->setGpa(4.0);
    // dog->setMajor("Branch_Managment");
    // dog->setRole(LAB_ASSISTANT);
    // dog->displayMember();
    // genPointer = dog;
    // genPointer->displayMember();
    // delete genPointer;
    // genPointer = nullptr;

    // Instructor* wolf = new Instructor(03, "lady", "Wolf");
    // wolf->setContact("badWolf@dr.who");
    // wolf->setOffice("HN 443");
    // wolf->displayMember();
    // genPointer = wolf;
    // genPointer->displayMember();
    // delete genPointer;
    // genPointer = nullptr;

    return 0;
}