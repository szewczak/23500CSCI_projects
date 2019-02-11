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

// #include <iostream>
// #include "CourseMember.hpp"
// #include "Student.hpp"
// #include "Instructor.hpp"
// #include "TeachingAssistant.hpp"
// using namespace std;

// int main(){
//     CourseMember nsz(5,"nick","szewczak");
//     cout << nsz.getFirstName() << endl;
//     cout << nsz.getLastName() << endl;
//     cout << nsz.getID() << endl;
//     coud << nsz.getGPA()

//     Student jimmy(6,"Jimmy","Jerkface");
//     cout << jimmy.getFirstName() << endl;
//     cout << jimmy.getLastName() << endl;
//     cout << jimmy.getID() << endl;
    
//     Instructor Tommala(6,"Tommala","Professor");
//     cout << Tommala.getFirstName() << endl;
//     cout << Tommala.getLastName() << endl;
//     cout << Tommala.getID() << endl;
    
//     TeachingAssistant Edberg(6,"Edberg","TA");
//     cout << Edberg.getFirstName() << endl;
//     cout << Edberg.getLastName() << endl;
//     cout << Edberg.getID() << endl;

//     return 0;
// }


#include <iostream>

#include "CourseMember.hpp"
#include "Student.hpp"
#include "TeachingAssistant.hpp"
#include "Instructor.hpp"

int main()
{
    CourseMember member1(1111, "Bob", "Chen");
    std::cout << member1.getID() << " " << member1.getFirstName() << " " << member1.getLastName() << std::endl;

    CourseMember member2(2222, "Bob", "Chen");
    std::cout << member2.getID() << " " << member1.getFirstName() << " " << member1.getLastName() << std::endl;

    CourseMember member3(3333, "Bob", "Chen");
    std::cout << member3.getID() << " " << member1.getFirstName() << " " << member1.getLastName() << std::endl;

    CourseMember member4(4444, "Bob", "Chen");
    std::cout << member4.getID() << " " << member1.getFirstName() << " " << member1.getLastName() << std::endl;

    Student s1(0001, "John", "Zhang");
    s1.setMajor("Education");
    s1.setGpa(3.7);
    std::cout << s1.getID() << " " << s1.getMajor() << " " << s1.getGpa() << std::endl;

    TeachingAssistant t1(9876, "David", "Yuen");
    t1.setMajor("Computer Science");
    t1.setGpa(3.3);
    t1.setHours(4);
    t1.setRole(LAB_ASSISTANT);
    std::cout << t1.getID() << " " << t1.getMajor() << " " << t1. getRole() << std::endl;

    Instructor i1(1000, "AAAA", "SSSS");
    i1.setOffice("HN1001E");
    i1.setContact("fuckyoufuckyou@fuck.com");
    std::cout << i1.getID() << " " << i1.getOffice() << " " << i1.getContact() << std::endl;

    return 0;
}