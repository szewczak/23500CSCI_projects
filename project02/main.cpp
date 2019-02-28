#include <vector>
#include <iostream>
#include "LinkedBag.hpp"
#include "Node.hpp"

using namespace std;


int main(){
    LinkedBag<string> testBag;
    LinkedBag<string> otherBag;
    testBag.add("testbag1");
    testBag.add("1st");
    testBag.add("2nd");
    testBag.add("1st");
    testBag.add("testbaglast");
    otherBag.add("otherbag1");
    otherBag.add("1st");
    otherBag.add("3rd");
    otherBag.add("2nd");
    otherBag.add("otherbaglast");
    LinkedBag<string> resultBag = testBag.bagUnion(otherBag);

    resultBag.removeRetainOrder("2nd");

    vector<string> bag_vector = resultBag.toVector();
    for (int i=0; i < resultBag.getCurrentSize(); i++){
        cout << bag_vector[i] << endl;
    }
    cout << resultBag.getFrequencyOf("1st") << endl;
    return 0;
}