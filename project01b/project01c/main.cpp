

#include <iostream>
#include "ArrayBag.hpp"

using namespace std;

void displayBag(ArrayBag<string>& bag)
{
    cout << "The bag contains " << bag.getCurrentSize()<< " items:" << endl;
    vector<string> bagItems = bag.toVector();
    int numberOfEntries = (int)bagItems.size();
    for (int i = 0; i < numberOfEntries; i++)
    {
        cout << bagItems[i] << " ";
    } // end for
    cout << endl << endl;
}
 // end displayBag



int main()
{
    ArrayBag<string> arr1;

    arr1.add("Happy");
    arr1.add("Happy");
    arr1.add("zzzz");
    arr1.add("bbbb");
    arr1.add("bbbbb");
    arr1.add("aaaa");

    ArrayBag<string> arr2;

    arr2.add("1");
    arr2.add("123");
    arr2.add("zzzz");
    arr2.add("1222");
    arr2.add("bbbbb");
    arr2.add("423");
    arr2.add("3353");
    arr2.add("Happy");


    ArrayBag<string> arr3;

    arr3 = arr1.bagUnion(arr2);
    cout << "This is arr3" << endl;
    displayBag(arr3);

    ArrayBag<string> arr4;

    arr4 = arr1.bagIntersectionNoDuplicates(arr2);
    cout << "This is arr4" << endl;
    displayBag(arr4);
/*
    ArrayBag<string> arr5;
    arr5 = arr1.bagDifference(arr2);
    cout << "This is arr5" << endl;
    displayBag(arr5);*/

    return 0;
}