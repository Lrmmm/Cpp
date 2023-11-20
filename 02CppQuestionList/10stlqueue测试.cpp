#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> myQue;
    myQue.push(1);
    myQue.push(2);
    myQue.push(3);

    myQue.pop();
    cout << myQue.front() << endl;
    return 0;
}