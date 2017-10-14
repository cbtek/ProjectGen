/*
    ConcurrentQueue.hpp
    

*/
#pragma once

#include <queue>
#include <thread>
#include <mutex>
#include <set>
#include <vector>
#include <condition_variable>

namespace cbtek {
namespace common {
namespace utility {

template <typename T>
class ConcurrentQueue
{
public:
    T pop()
    {
        std::unique_lock<std::mutex> mlock(m_mutex);
        while (m_queue.empty())
        {
            m_cond.wait(mlock);
        }
        auto item = m_queue.front();
        m_queue.pop();
        return item;
    }

    void pop(T& item)
    {
        std::unique_lock<std::mutex> mlock(m_mutex);
        while (m_queue.empty())
        {
            m_cond.wait(mlock);
        }
        item = m_queue.front();
        m_queue.pop();
    }

    void push(const T& item)
    {
        std::unique_lock<std::mutex> mlock(m_mutex);
        m_queue.push(item);
        mlock.unlock();
        m_cond.notify_one();
    }

    void push(T&& item)
    {
        std::unique_lock<std::mutex> mlock(m_mutex);
        m_queue.push(std::move(item));
        mlock.unlock();
        m_cond.notify_one();
    }

    size_t size()
    {
        std::unique_lock<std::mutex> mlock(m_mutex);
        size_t size = m_queue.size();
        mlock.unlock();
        return size;
    }


    /**
     * @brief clear
     */
    void clear()
    {
        std::unique_lock<std::mutex> mlock(m_mutex);
        size_t count = m_queue.size();
        for(size_t a1 = 0; a1 < count; ++a1)
        {
            m_queue.pop();
        }
        mlock.unlock();
    }


    private:
    std::queue<T> m_queue;
    std::mutex m_mutex;
    std::condition_variable m_cond;
};
}}}//end namespace
