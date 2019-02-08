#include <iostream>
#include "CourseMember.hpp"

int main(){
    CourseMember Student(5,"nick","szewczak");
    std::cout << Student.getFirstName() << std::endl
         << Student.getLastName() << std::endl
         << Student.getID() << std::endl;
    return 0;
}