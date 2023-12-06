#include <iostream>
#include <vector>
#include "thread_pool.hpp"
#include <chrono>
#include <thread>
using namespace std;
mutex io_mutex;
void echo()
{
    for (int i=0; i < 100; i++)
    {
        cout << "Echo : "<<i<<endl;
        io_mutex.lock();
        std::this_thread::sleep_for(std::chrono::seconds(1));
        io_mutex.unlock();

    }
}

int fib(int n){
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    return fib(n-1)+fib(n-2);
}

int main() {
    ThreadPool myThreadPool(1);
    myThreadPool.init();
    // myThreadPool.submit(echo);
    // myThreadPool.submit(echo);
    auto myFuture1 = myThreadPool.submit(fib,3);
    auto myFuture2 = myThreadPool.submit(fib,4);
    auto myFuture3 = myThreadPool.submit(fib,5);
    auto myFuture4 = myThreadPool.submit(fib,6);
    cout << myFuture1.get() << endl;
    cout << myFuture2.get() << endl;
    cout << myFuture3.get() << endl;
    cout << myFuture4.get() << endl;
    
    myThreadPool.shutdown();
    return 0;
}