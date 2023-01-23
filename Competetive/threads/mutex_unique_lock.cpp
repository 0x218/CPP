#include <iostream>
#include <mutex>
#include <thread>

/*
NOTE:
    unique_lock is a mutex ownership wrapper.
    1. it has different locking strategies - defer_lock, try_to_lock, adopt_lock.
    2. it has time constrained lock attemsp - try_lock_for, try_lock_unitl
    3. it can recursive lock
    4. it can transfer lock ownership
    5. condition_variables are accepted.


    defer_lock - do not acquire ownership of mutex
    try_to_lock- try to acquire ownership of mutex without blocking
    adopt_lock - assume the calling thread already has ownership of mutex.
*/


std::mutex mux;
int buffer = 0;


void doTheTask(const char* threadNum, int loop){
    std::unique_lock<std::mutex> ulock(mux, std::defer_lock);//due to defer_lock it will not lock mux at this point, but ->
    ulock.lock(); //it will lock mux at this point.

    for (int i = 0; i < loop; ++i){
        ++ buffer;
        std::cout<<threadNum<<" "<<buffer<<std::endl;
    }
    //no ulock.unlock() to be called.  it is automatically handled.

}


int main(){
    std::thread t1(doTheTask, "T1", 10);
    std::thread t2(doTheTask, "T2", 10);

    t1.join();
    t2.join();

    return 0;
}