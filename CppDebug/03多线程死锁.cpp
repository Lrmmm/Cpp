#include <iostream>
#include <vector>
#include <mutex>
#include <thread>
using namespace std;

mutex mtx1;
mutex mtx2;
mutex mtx3;

void func1()
{
    lock_guard<mutex> lock1(mtx1);
    this_thread::sleep_for(chrono::seconds(1));
    lock_guard<mutex> lock2(p );
    this_thread::sleep_for(chrono::seconds(1));
}

void func2()
{
    lock_guard<mutex> lock2(mtx2);
    this_thread::sleep_for(chrono::seconds(1));
    lock_guard<mutex> lock3(mtx3);
    this_thread::sleep_for(chrono::seconds(1));
}

void func3()
{
    lock_guard<mutex> lock3(mtx3);
    this_thread::sleep_for(chrono::seconds(1));
    lock_guard<mutex> lock1(mtx1);
    this_thread::sleep_for(chrono::seconds(1));
}

int main() {
    thread t1(func1);
    thread t2(func2);
    thread t3(func3);

    if(t1.joinable())
        t1.join();
    if(t2.joinable())
        t2.join();
    if(t3.joinable())
        t3.join();
    return 0;
}