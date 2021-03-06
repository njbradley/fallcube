#include "pool.h"
#include <mutex>
#include <condition_variable>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>

Pool::Pool(int num) {
    num_threads = num;
    job_queue = std::queue< std::function<void()> > ();
    is_alive = true;
    pool.resize(num_threads);

    for (int i = 0; i < num_threads; i++) {
        pool[i] = std::thread(&Pool::thread_loop, this);
    }

}

void Pool::thread_loop() {
    
    while (true) {
        {
            std::function<void()> job;
            {
                std::unique_lock<std::mutex> lock(queue_mutex);

                v.wait(lock, [&] { return !job_queue.empty() || !is_alive; });
                
                if (!is_alive) {
                    return;
                }
                job = job_queue.front();
                job_queue.pop();
            }

            job(); // function<void()> type
        }
       
    }
}

void Pool::pushJob(const std::function<void()>& job) {
    {
        std::unique_lock<std::mutex> lock(queue_mutex);
        job_queue.push(job);
    }

    v.notify_one();
}

Pool::~Pool() {
    {
        std::unique_lock<std::mutex> lock(queue_mutex);
        is_alive = false;
    }
    v.notify_all();
    for (std::thread& active_thread : pool) {
        active_thread.join();
    }
    pool.clear();
}