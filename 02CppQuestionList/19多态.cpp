#include <iostream>
#include <vector>
using namespace std;
class Base{
public:
    string name;
    virtual void echo(){cout << "I am Base"<<endl;}
};
class Derive : public Base{
public:
    virtual void echo(){cout << "I am Derive"<<endl;}
};
int main() {
    Base *p = new Derive();
    Derive a;
    p->echo();
    return 0;
}