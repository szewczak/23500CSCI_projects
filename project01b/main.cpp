//TEST
//This file is used for testing purposes before uploading to Gradescope


#include <iostream>
#include "BagTest.hpp"
#include "ArrayBag.hpp"
#include "CourseMember.hpp"
using namespace std;


int main()
{
    BagTest maintestbag;
    ArrayBag<CourseMember> arraymate = maintestbag.testCourseMemberBag();
    maintestbag.displayCourseMemberBag(arraymate);
    return 0;
}