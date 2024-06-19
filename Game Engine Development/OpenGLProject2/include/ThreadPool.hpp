#ifndef THREAD_POOL_HPP
#define THREAD_POOL_HPP

#include <vector>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <stdexcept>

class ThreadPool {
public:
    ThreadPool(size_t threads);
    ~ThreadPool();

    void enqueue(std::function<void()> task);

private:
    // need to keep track of threads so we can join them
    std::vector<std::thread> workers;
    // the task queue
    std::queue<std::function<void()>> tasks;

    // synchronization
    std::mutex queueMutex;
    std::condition_variable condition;
    bool stop;
};

#endif // THREAD_POOL_HPP
