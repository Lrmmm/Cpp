#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

static void dead_loop(void)
{
    while(1)
        continue;
}

int main()
{
    thread threads[4];

    for(int i=0; i < 4; i++)
    {
        threads[i] = std::thread(dead_loop);
        cout << "thread id = " << threads[i].get_id() << endl;
    }

    // getchar();
    this_thread::sleep_for(chrono::seconds(100));

    return 0;
}