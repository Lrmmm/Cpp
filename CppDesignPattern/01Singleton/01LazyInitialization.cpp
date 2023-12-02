/*
 * C++设计模式之单例模式
 *
 * version1:
 * with problems below:
 * 1. thread is not safe
 * 2. memory leak
 * */

#include <iostream>

using namespace std;

class Singleton{
private:
    static Singleton* m_pInstance;

private:
    Singleton(){
        cout << "constructor called!" << endl;
    }

    Singleton(Singleton&)=delete;
    Singleton& operator=(const Singleton&)=delete;

public:
    ~Singleton(){
        cout << "destructor called!" << endl;
    }

    static Singleton* getInstance() {
        if (m_pInstance == nullptr) {
            m_pInstance = new Singleton;
        }

        return m_pInstance;
    }
};

Singleton* Singleton::m_pInstance = nullptr;

int main() {
    Singleton* instance1 = Singleton::getInstance();
    Singleton* instance2 = Singleton::getInstance();

    return 0;
}
