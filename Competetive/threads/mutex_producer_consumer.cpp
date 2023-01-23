#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <deque>


std::mutex mux;
std::condition_variable cond;
std::deque<int> buffer;
const unsigned int max_buffer = 50;

void producer(int val){
    while (val){
        std::unique_lock<std::mutex> ulock(mux);
        cond.wait(ulock, [](){
            return (buffer.size() < max_buffer);
        });


        buffer.push_back(val);
        std::cout<<"Produced "<<val<<std::endl;
        --val;
        ulock.unlock();
        cond.notify_all();
    }
}


void consumer(){
    while(true){
        std::unique_lock<std::mutex> ulock (mux);
        cond.wait(ulock, []() {
            return (buffer.size() > 0);
        });
        int val = buffer.back();
        buffer. pop_back();
        std::cout<<"Consumed "<<val<<std::endl;
        mux.unlock();
        cond.notify_all();
    }
}


int main(){
    std::thread tProducer(producer, 100);
    std::thread tConsumer (consumer);

    tProducer.join();
    tConsumer.join();

    return 0;
}