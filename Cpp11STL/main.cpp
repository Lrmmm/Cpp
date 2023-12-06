#include <iostream>
#include <vector>
#include "shared_ptr.hpp"
using namespace std;
class Person{
private:
    string name;
public:
    Person(string name):name(name){};
    void echo(){ cout << "Name:"<<name<<endl;}
};
void test1()
{
    lrm::shared_ptr<Person> p1(new Person("lrm"));
    lrm::shared_ptr<Person> p2 = p1;
    cout << p1.userCount() << endl;
    p1->echo();

}
int main() {
    test1();
    vector<int> myArray = {1,2,3,4,5};
    vector<int>::iterator it = myArray.begin();
    cout << *it << endl;
    *it = 99;
    for(vector<int>::iterator it = myArray.begin(); it != myArray.end(); it++){
        cout << *it <<" ";
    }
    return 0;
}