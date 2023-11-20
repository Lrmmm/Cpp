#include<iostream>
using namespace std;
class A {
    private:
        int  a;
    public:
        virtual void f() {
            cout<<"A::f()"<<endl;
        }
        virtual void g() {
            cout<<"A::g()"<<endl;
        }
};
class B:public A {
    private:
        int b;
    public:
        virtual void f() {
            cout<<"B::f()"<<endl;   
        }
        virtual void g1() {
            cout<<"B::g1()"<<endl;
        }
        void h() {
            cout<<"B::h()"<<endl;
        }
};
int main()
{
    typedef void(*fun)(void);
    fun pFun;
    A a;
    B b;
    return 0;
}