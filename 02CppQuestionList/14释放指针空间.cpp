#include <iostream>
using namespace std;

int main() {
    int *p1 = new int[8];
    int *p2 = new int[2];
    p1 = p2 ;
    delete[] p1;
    return 0;
}