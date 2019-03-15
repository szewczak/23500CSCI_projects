
#include <iostream>
#include <fstream>
#include "polytest.hpp"
#include <string>
/**
 @param cm_list the list to be populated with pointers to CourseMember
 @param input_file the file containing data used to generate CourseMemberderived objects to add to cm_list
 @post reads parameters from input_file to call addMemberToList()
 */
void populateCmList(List<CourseMember*>& cm_list, std::string input_file){
    // some pseudocode:
    //temps
    int id;
    std::string ids;
    std::string fnm;
    std::string lnm;
    std::string title;

    std::fstream in_stream(input_file);
    if(!in_stream.is_open()){
        std::cerr << "cannot read from " << input_file << std::endl;
        return;
    }
    while(std::getline(in_stream, ids, ',') && std::getline(in_stream, fnm, ',') && std::getline(in_stream, lnm, ',') && std::getline(in_stream, title, '\n')){
        if(!in_stream.eof()){
            title.pop_back();
        }
        id = stoi(ids);
        // std::cout << "the title is " << title << std::endl;
        addMemberToList(cm_list, id, fnm, lnm, title);
    }
    in_stream.close();
}

/**
 @post instantiates a new object - Student, TeachingAssistant or Instructor -
 as indicated by the title parameter, randomly generate relevant data not
 provided by parameters (e.g. major_, gpa_ etc.) and append a pointer to
 cm_list that points to the newly instantiated object
 */
void addMemberToList(List<CourseMember*>& cm_list, int id, const std::string& first_name, const std::string& last_name, const std::string& title){
    CourseMember* genPointer;
    if(title == "Student"){
        // std::cout << "this is Student\n";
        Student* a_courseMember = new Student(id, first_name, last_name);
        a_courseMember->setGpa(randGpa());
        a_courseMember->setMajor(randMajor());
        genPointer = a_courseMember;
    }
    if(title == "Teaching Assistant"){
        // std::cout << "this is Teaching Assistant\n";
        TeachingAssistant* a_courseMember = new TeachingAssistant(id, first_name, last_name);
        a_courseMember->setGpa(randGpa());
        a_courseMember->setMajor(randMajor());
        a_courseMember->setHours(rand() % 12); // hours 0-12
        a_courseMember->setRole(randRole());
        genPointer = a_courseMember;
    }
    if(title == "Instructor"){
        // std::cout << "this is Instructor\n";
        Instructor* a_courseMember = new Instructor(id, first_name, last_name);
        a_courseMember->setOffice("1000C");
        a_courseMember->setContact("235Instructors@hunter.cuny.edu");
        genPointer = a_courseMember;
    }
    cm_list.insert(cm_list.getLength(),genPointer);
}

double randGpa(){
    // int temp = rand() % 40; // int random from 0-40
    // return temp/10;
    return rand() % 4;
}

std::string randMajor(){
    std::string majors[10] = {"Computer Science", "Literature", "Music", "Philosophy", "Physics", "Theatre", "Computational Biology", "Mathematics", "Geography", "Linguistics"};
    int index = rand() % 9; // rand 0-9
    return majors[index];
}

ta_role randRole(){
    ta_role roles [3] = {LAB_ASSISTANT, LECTURE_ASSISTANT, FULL_ASSISTANT};
    int index = rand() % 2; // random from 0-2
    return roles[index]; 
}

