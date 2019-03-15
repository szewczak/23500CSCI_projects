#include <vector>
#include <iostream>
#include "CourseMember.hpp"
#include "Student.hpp"
#include "TeachingAssistant.hpp"
#include "Instructor.hpp"


using namespace std;


int main(){
    Student cat(01,"Mr.", "Fluffy");
    cat.setGpa(3.2);
    cat.setMajor("scowling");
    cat.displayMember();
    
    TeachingAssistant dog(02, "Good", "Doggy");
    dog.setGpa(4.0);
    dog.setMajor("Branch_Managment");
    dog.setRole(BOTH);
    dog.displayMember();

    Instructor wolf(03, "lady", "Wolf");
    wolf.setContact("badWolf@dr.who");
    wolf.setOffice("HN 443");
    wolf.displayMember();

    return 0;
}