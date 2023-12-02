#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <atomic>
using namespace std;
mutex mymutex;
// atomic<int> g_number(0);
int g_number = 0;


/**
 * 1.++操作线程不安全,发生竞争态问题
 *  (1)使用锁 (2)使用atomic<int>关键字     
 *  
*/
void add_g_number(int n=10000){
    for (int i = 0; i < n; i++){
        g_number++;
    }
}
void test1(){
    thread myThread1(add_g_number,10000);
    thread myThread2(add_g_number,10000);
    myThread1.join();
    myThread2.join();
    cout << g_number << endl;
}


int main() {
    test1();

    return 0;
}