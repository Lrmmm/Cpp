#include <iostream>
#include <vector>
using namespace std;

class SingletonEager{
private:
    static SingletonEager m_instance;
    SingletonEager(){ cout << "constructor called!" << endl;};

public:
    ~SingletonEager(){cout << "destructor called!" << endl; }
    SingletonEager(const SingletonEager&) = delete;
    SingletonEager& operator=(const SingletonEager&) = delete;

    static SingletonEager* getInstance()
    {
        return &m_instance;
    }
};
SingletonEager SingletonEager::m_instance;

int main() {
    SingletonEager* instance1 = SingletonEager::getInstance();
    return 0;
}