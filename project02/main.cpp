#include <vector>
#include <iostream>
#include "LinkedBag.hpp"
#include "Node.hpp"

using namespace std;


int main(){
    LinkedBag<string> testBag;
    LinkedBag<string> otherBag;
    LinkedBag<string> resultBag;
    testBag.add("1st");
    testBag.add("2nd");
    testBag.add("1st");
    otherBag.add("1st");
    otherBag.add("3rd");
    resultBag = testBag.bagUnion(otherBag);

    vector<string> bag_vector = resultBag.toVector();
    cout << resultBag.getFrequencyOf("1st") << endl;
    return 0;
}