#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> myArry(10);
    cout <<"capacity:"<<myArry.capacity() << endl;
    myArry[9] = 9;
    myArry.push_back(99);

    vector<int> myArry2;
    myArry2.push_back(1);
    myArry2.push_back(1);
    myArry2.push_back(1);
    myArry2[5] = 9;
    myArry2[9] = 9;

    cout << myArry2.capacity() << endl;
    cout << myArry2[5] << endl;
    return 0;
}