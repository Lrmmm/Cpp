#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int myArry[99];
    unordered_map<int,int> myMap;
    for (int i = 0; i < 18; i++)
    {
        myArry[i] = i;
        myMap[i] = i;
    }
    
    cout << sizeof(myArry) << endl;
    cout << sizeof(myMap) << endl;
    cout << myMap.bucket_count() << endl;
    cout << myMap.load_factor() << endl;
    return 0;
}