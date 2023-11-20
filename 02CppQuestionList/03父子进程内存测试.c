#include<unistd.h>
#include<stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
int a = 99;
int main()
{
    int* p = 0x300;
    *p = 99;
    int status;

    if (fork() == 0) {
        *p = 100;
        printf("children : a = %d address=%p \n",*p, p);
        exit(1);
    }

    wait(&status);
    printf("father : a = %d address=%p \n", *p,  p);


    return 0;
}