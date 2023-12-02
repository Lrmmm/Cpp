#pragma once

#include <mutex>
#include <queue>
#include <functional>
#include <future>
#include <thread>
#include <utility>
#include <vector>
using namespace std;

// 基于Queue实现的，线程安全队列
template<class T>
class SafeQueue{
public:
    SafeQueue(){}
    SafeQueue(SafeQueue &&other) {}  // 右值引用作为函数参数
    ~SafeQueue(){}

    bool empty(){
        unique_lock<mutex> lock(m_mutex);
        return m_queue.empty();
    }

    int size() {
        unique_lock<mutex> lock(m_mutex);
        return m_queue.size();
    }

    void enqueue(T &t){
        unique_lock<mutex> lock(m_mutex);
        m_queue.emplace(t);
    }

    bool dequeue(T &t){
        unique_lock<mutex> lock(m_mutex);
        if (m_queue.empty())
            return false;
        t = std::move(m_queue.front());
        m_queue.pop();
        return true;
    }
private:
    queue<T> m_queue;
    mutex m_mutex;  // 读写互斥锁
};

class ThreadPool
{
private:
    bool m_shutdown;
    SafeQueue<function<void()>> m_queue;
    vector<thread> m_threads;
    mutex m_conditional_mutex;
    condition_variable m_conditional_lock;
    class ThreadWorker{
    private:
        int m_id;
        ThreadPool *m_pool;
    public:
        ThreadWorker(ThreadPool *pool, const int id) : m_pool(pool),m_id(id){}
        void operator()(){
            std::function<void()>func;
            bool dequeued;
            while (!m_pool->m_shutdown)
            {
                {
                    unique_lock<mutex> lock(m_pool->m_conditional_mutex);
                    if (m_pool->m_queue.empty())
                        m_pool->m_conditional_lock.wait(lock);
                    dequeued = m_pool->m_queue.dequeue(func);
                }
                if (dequeued)
                    func();
            }
            
        }
    };
public:
    ThreadPool(const int n_threads = 4):m_threads(vector<thread>(n_threads)),m_shutdown(false){}

    ThreadPool(const ThreadPool& ) = delete;

    ThreadPool(ThreadPool && ) = delete;

    ThreadPool &operator=(const ThreadPool &) = delete;

    ThreadPool &operator=(ThreadPool &&) = delete;

    void init()
    {
        for (int i = 0; i < m_threads.size(); i++)
            m_threads.at(i) = thread(ThreadWorker(this,i));
        
    }

    void shutdown(){
        m_shutdown = true;
        m_conditional_lock.notify_all();

        for (int i = 0; i < m_threads.size(); i++)
        {
            if (m_threads.at(i).joinable())
                m_threads.at(i).join();
        }
        
    }

    template<class F, typename... Args>
    auto submit(F &&f, Args &&...args) -> future<decltype(f(args...))>
    {
        function<decltype(f(args...))()> func = std::bind(std::forward<F>(f), std::forward<Args>(args)...);
        auto task_ptr = std::make_shared<std::packaged_task<decltype(f(args...))()>>(func);
        std::function<void()> warpper_func = [task_ptr]()
        {
            (*task_ptr)();
        };
        m_queue.enqueue(warpper_func);
        m_conditional_lock.notify_one();
        return task_ptr->get_future();
    }

};