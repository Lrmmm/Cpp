/*
 * C++设计模式之单例模式 --线程安全的懒汉模式
 *  1. 懒汉模式Singleton* Singleton::m_pInstance = nullptr
 *  2. 懒汉模式会存在竞态问题，所以要实现线程安全的懒汉模式
 * 
 * 
 * */

#include <iostream>
#include <mutex>

using namespace std;

class SingletonLazy{
private:
    static SingletonLazy* m_pInstance;
    static mutex m_mtx;

    SingletonLazy(){ cout << "constructor called!" << endl; }

    SingletonLazy(SingletonLazy&)=delete;
    SingletonLazy& operator=(const SingletonLazy&)=delete;

public:
    ~SingletonLazy(){ cout << "destructor called!" << endl; }

    static SingletonLazy* getInstance() {
        if (m_pInstance == nullptr) {
            std::lock_guard<mutex> lock(m_mtx);
            if(m_pInstance == nullptr){
                m_pInstance = new SingletonLazy();
            }
        }

        return m_pInstance;
    }
};

SingletonLazy* SingletonLazy::m_pInstance = nullptr;
mutex SingletonLazy::m_mtx;

int main() {
    SingletonLazy* instance1 = SingletonLazy::getInstance();
    SingletonLazy* instance2 = SingletonLazy::getInstance();
    return 0;
}
