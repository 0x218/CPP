#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>

std::mutex mux1, mux2;
int X = 0, Y = 0;

void increment(int &var, std::mutex &mux, const char* desc){
    for (int i = 0; i < 5; ++i){
        mux.lock();
        ++var;
        std::cout<<desc<< " " <<var<<std::endl;
        mux.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}


void consumeXY(){
    int useCount = 5;
    int xPlusy = 0;
    while(true){

        //try_lock tries to lock all mutexes passed in it.  If locked, returns -1; else return 0-based mutex index number that it can't lock.
        int lockResult = std::try_lock(mux1, mux2);

        if (lockResult == -1){//achieved lock.
            if (X != 0 && Y != 0){
                --useCount;
                xPlusy += X + Y;
                X = Y = 0;
                std::cout<<"x + y "<<xPlusy<<std::endl;
            }
            mux1.unlock();
            mux2.unlock();

            if (useCount == 0) break;
        }
    }
}


int main(){
    std::thread t1(increment, std::ref(X), std::ref(mux1), "X ");
    std::thread t2(increment, std::ref(Y), std::ref(mux2), "Y ");
    std::thread t3(consumeXY);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}