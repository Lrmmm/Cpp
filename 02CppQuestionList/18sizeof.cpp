#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
class Person{
    char name;
    int a;
};
int main() {
    Person p1;
    char a[] = "hello";
    cout << sizeof(p1) <<endl;
    cout << sizeof(a) <<endl;
    cout << strlen(a) <<endl;
    return 0;
}