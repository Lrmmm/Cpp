#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    map<int,string> myMap;
    myMap[6] = "Hello";
    myMap[7] = "Hello";
    myMap[8] = "Hello";
    myMap[9] = "Hello";
    myMap[10] = "Hello";
    myMap[1] = "Hello";
    myMap[2] = "Hello";
    myMap[3] = "Hello";
    myMap[4] = "Hello";
    myMap[5] = "Hello";
    auto it = myMap.end();

    cout << (*(it-2)).first << endl;
    return 0;
}