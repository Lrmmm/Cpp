#include<iostream>
using namespace std;
class Base
{
public:
    virtual void f(float x){ cout << "Base::f(float) " << x << endl; }
    void g(float x,float y){ cout << "Base::g(float) " << x << endl; }
    void h(float x){ cout << "Base::h(float) " << x << endl; }
};

class Derived : public Base
{
public:
    virtual void f(float x){ cout << "Derived::f(float) " << x << endl; }
    void g(float x,float y){ cout << "Derived::g(int) " << x << endl; }
    void h(float x){ cout << "Derived::h(float) " << x << endl; }
};

int main()
{
    Base* ptr = new Derived();
    ptr->g(1,2);
    return 0;
}