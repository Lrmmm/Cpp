#include <mutex>
#include <condition_variable>
#include <queue>
using namespace std;
template<class T>
class MessageQueue{
public:
    void push(const T& msg){
        unique_lock<mutex> lock(m_mutex);
        m_queue.push(msg);
        m_cv.notify_one();
    }

    bool poll(T& msg) {
        std::unique_lock<mutex> lock(m_mutex);
        if(m_queue.size()){
            msg = m_queue.front();
            m_queue.pop();
            return true;
        }
        return false;
    }

    void wait(T& msg){
        unique_lock<mutex> lock(m_mutex);
        while(!m_queue.size()) m_cv.wait(lock);  // 会阻塞并解锁互斥量，直到有个线程调用notify
        msg = m_queue.front();
        m_queue.pop();
    }

    int size(){
        std::unique_lock<mutex> lock(mutex);
        return m_queue.size();
    }

private:
    std::queue<T> m_queue;
    std::mutex m_mutex; 
    std::condition_variable m_cv;
};