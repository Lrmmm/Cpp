#include <iostream>
using namespace std;

int main() {
    string str = "你好世界";
    for (int i = 0 ; i< str.size() ;i++)
        cout << str[i];
    cout << str << endl;
    return 0;
}