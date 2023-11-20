#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> myArry;
    cout <<"capa: " <<  myArry.capacity() << "  size"<<  myArry.size() << endl;
    myArry.push_back(1);
    cout <<"capa: " <<  myArry.capacity() << "  size"<<  myArry.size() << endl;
    myArry.push_back(1);
    cout <<"capa: " <<  myArry.capacity() << "  size"<<  myArry.size() << endl;
    myArry.push_back(1);
    cout <<"capa: " <<  myArry.capacity() << "  size"<<  myArry.size() << endl;
    myArry.push_back(1);
    cout <<"capa: " <<  myArry.capacity() << "  size"<<  myArry.size() << endl;
    myArry.push_back(1);
    cout <<"capa: " <<  myArry.capacity() << "  size"<<  myArry.size() << endl;


    return 0;
}
