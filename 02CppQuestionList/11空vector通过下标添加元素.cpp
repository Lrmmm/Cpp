#include <iostream>
#include <vector>
using namespace std;
/**
 * 1. 不要用下标的方式往vector中添加元素，会发生segment fault
 * 
*/
int main() {
    vector<int> myArr;
    myArr.push_back(0);
    myArr[3] = 1;
    cout << myArr[3] <<endl;
    cout << myArr.size() <<endl;
    cout << myArr.capacity() << endl;
    cout << myArr[0] << endl;
    return 0;
}