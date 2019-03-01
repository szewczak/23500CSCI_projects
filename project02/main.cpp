#include <vector>
#include <iostream>
#include "LinkedBag.hpp"
#include "Node.hpp"

using namespace std;


int main(){
    LinkedBag<int> bag_1;
    LinkedBag<int> bag_2;
    vector<int> bag_vector;
    // populate bags
     bag_1.add(2);
     bag_1.add(4);
     bag_1.add(2);
     bag_1.add(8);
     bag_1.add(5);
     bag_1.add(1);
     bag_1.add(2);
     bag_1.add(3);
     bag_1.add(4);
     bag_1.add(2); 
     cout << "bag 1\n";
     bag_vector = bag_1.toVector();
     for (int i=0; i < bag_1.getCurrentSize(); i++) cout << bag_vector[i] << ", ";
 
     bag_2.add(0);
     bag_2.add(2);
     bag_2.add(1);
     bag_2.add(5);
     bag_2.add(1);
     bag_2.add(8);
     bag_2.add(1);
     bag_2.add(6);
     bag_2.add(7);
     bag_2.add(9); 
    //  cout << "\nbag 2\n";
    //  bag_vector = bag_2.toVector();
    //  for (int i=0; i < bag_2.getCurrentSize(); i++) cout << bag_vector[i] << ", ";
    // // tests

    // cout << "\n\nunionBag\n";
    // LinkedBag<int> unionBag = bag_1;
    // unionBag.bagUnion(bag_2);
    // vector<int> vector_unionBag = unionBag.toVector();
    // for(int i=0; i<unionBag.getCurrentSize();i++){
    //     cout << vector_unionBag[i] << ", ";
    // }    

    // cout << "\n\nnoDubIntersectBag\n";
    // LinkedBag<int> noDubIntersectBag = bag_1;
    // noDubIntersectBag.bagIntersectionNoDuplicates(bag_2);
    // vector<int> vector_noDubIntersectBag = noDubIntersectBag.toVector();
    // for(int i=0; i<noDubIntersectBag.getCurrentSize();i++){
    //     cout << vector_noDubIntersectBag[i] << ", ";
    // }    

    // cout << "\n\nDifferenceBag\n";
    // LinkedBag<int> DifferenceBag = bag_1;
    // DifferenceBag.bagDifference(bag_2);
    // vector<int> vector_DifferenceBag = DifferenceBag.toVector();
    // for(int i=0; i<DifferenceBag.getCurrentSize();i++){
    //     cout << vector_DifferenceBag[i] << ", ";
    // }    
    // cout << "\n\nBag_1 originally:\n";
    // LinkedBag<int> smoothRemoveBag = bag_1;
    // vector<int> vector_bag_1 = bag_1.toVector();
    // for(int i=0; i<bag_1.getCurrentSize();i++){
    //     cout << vector_bag_1[i] << ", ";
    // }

    cout << "\n\naddingEndBag, adding 99\n";
    LinkedBag<int> addingEndBag = bag_1;
    addingEndBag.addToEnd(99);
    vector<int> vector_addingEndBag = addingEndBag.toVector();
    for(int i=0; i<addingEndBag.getCurrentSize();i++){
        cout << vector_addingEndBag[i] << ", ";
    }

    // cout << "\nafter remove:\n";
    // smoothRemoveBag.removeRetainOrder(1);
    // vector<int> vector_smoothRemoveBag = smoothRemoveBag.toVector();
    // for(int i=0; i<smoothRemoveBag.getCurrentSize();i++){
    //     cout << vector_smoothRemoveBag[i] << ", ";
    // }    

    cout << "\ndone with tests\n";

    


    // LinkedBag<int> resultBag = bag_1;

    // resultBag.removeRetainOrder(8);


    // vector<int> final_bag_vector = resultBag.toVector();

    // cout << "\n\nafter ******(\"2nd)\"\n\n";
    // final_bag_vector = resultBag.toVector();
    // for (int i=0; i < resultBag.getCurrentSize(); i++)cout << final_bag_vector[i] << endl;
    
    return 0;
}