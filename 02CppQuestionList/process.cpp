#include<iostream>
#include<unistd.h>
#include<sys/wait.h>
using namespace std;

int main()
{
    int pid = getpid();
    int ppid = getppid();
    if (fork() == 0) {
        // int pid = getpid();
        // int ppid = getppid();
        cout << "I am children process, my pid:"<<getpid()<<", my father pid:" << getppid()<< endl;
        return 0;
    }
    cout << "I am parent process, my pid:"<<pid<<", my father pid:" << ppid<< endl;
    wait(NULL);
    return 0;
}