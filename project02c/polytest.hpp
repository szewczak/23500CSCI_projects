/**
// @file polytest.hpp
// Project2C
//
// created by Nick Szewczak 2019.03.15
*/

#ifndef polytest_hpp
#define polytest_hpp




// does the following
// * read data from an input file with format like roster.csv:
//   id, first_name,last_name,title
//
// * for each line in the input file, instantiate an object of type Student, TeachingAssistant or Instructor, as indicatged by teh title (the last field on each line).
//
// * randomly generate data spoecific to an object that is not provided in the input file, while all Instructor objects will have the same email (235Instructors@hunter.cuny.edu) and the same office (1000C).
//
// * APPEND each of these objects via pointer to a List<CourseMember*>
/**
 @param cm_list the list to be populated with pointers to CourseMember
 @param input_file the file containing data used to generate CourseMemberderived objects to add to cm_list
 @post reads parameters from input_file to call addMemberToList()
 */
void populateCmList(List<CourseMember*>& cm_list, std::string input_file);



#endif /* polytest_hpp */