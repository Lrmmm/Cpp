#include <iostream>
#include <vector>
using namespace std;

int main() {
    const int a = 9;
    auto b = a;
    b = 10;
    cout << a << endl;
    cout << a << endl;
    return 0;
}