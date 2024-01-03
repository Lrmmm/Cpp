/**
 *  1. 死锁代码
 *    ABBA型死锁
*/

#include <iostream>
#include <vector>
#include <mutex>
#include <thread>
using namespace std;

class Resource{
public:
    mutex mtx;
    /* data ... */
};

Resource r1;
Resource r2;
void funThread1(){

    while(true)
    {
        {
            cout <<"Thread : " << this_thread::get_id() << ", waiting for r1" << endl;
            lock_guard<mutex> lock1(r1.mtx);
            cout <<"Thread : " << this_thread::get_id() << ", get r1 , waiting for r2" << endl;
            lock_guard<mutex> lock2(r2.mtx);
            cout <<"Thread : " << this_thread::get_id() << ", get r2, running" << endl;
        }
        this_thread::sleep_for(1000ms);
    }
}

void funThread2()
{
    while(true)
    {
        {
            cout <<"Thread : " << this_thread::get_id() << ", waiting for r2" << endl;
            lock_guard<mutex> lock1(r2.mtx);
            cout <<"Thread : " << this_thread::get_id() << ", get r2 , waiting for r1" << endl;
            lock_guard<mutex> lock2(r1.mtx);
            cout <<"Thread : " << this_thread::get_id() << ", get r1, running" << endl;
        }
        this_thread::sleep_for(1000ms);
    }
}
int main() {

    thread th1(funThread1);
    thread th2(funThread2);
    if(th1.joinable())
        th1.join();
    if(th2.joinable())
        th2.join();
    return 0;
}