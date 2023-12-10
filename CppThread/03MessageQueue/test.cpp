#include "MessageQueue.hpp"
#include <thread>
#include <iostream>
#include <stdio.h>
using namespace std;
class Message{
public:
    int type;
    void *param1;
    void *param2;
};

// 等待消息
void test1(){
    MessageQueue<Message> mq;
    thread t1([&](){
        Message msg;
        while(1){
            mq.wait(msg);
            cout << "receive message type:"<<msg.type<<endl;
            if (msg.type == 1001)
                break;
        }
        printf("Thread1 exited\n");
    });

    Message msg;
    printf("Send number message to thread.1001 exit\n");
    while(1)
    {
        cin >> msg.type;
        mq.push(msg);
        if (msg.type == 1001)
            break;
    }
    t1.join();
}


// 轮询消息
void test2()
{
    MessageQueue<Message> mq;
    thread t1([&](){
        Message msg;
        while(1){
            if(mq.poll(msg))
            {
                printf("receive message type:%d\n", msg.type);
                if(msg.type == 1001)
                    break;
            }
            this_thread::sleep_for(chrono::milliseconds(10));
        }
        printf("thread exited\n");
    });

    Message msg;
    printf("send number message to thread.1001 exit\n");
	while (1)
	{
		scanf("%d", &msg.type);
		mq.push(msg);
		if (msg.type == 1001)
			break;
	}
	t1.join();
}

int main(){
    // test1();
    test2();
}