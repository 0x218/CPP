#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>



std::mutex mux;
std::condition_variable cond_var;
bool ready = false; //flag for threads to run
int current = 0;// track current thread id.

void print_num(int num, int max){
    std::unique_lock<std::mutex> ulock(mux);

    while(num != current || !ready)
    {
        cond_var.wait(ulock); //wiat until thread is ready and expected thread id (current) arrives 
    }
    ++current; //go for next thread id.

    std::cout<<"Thread: "<<num+1<<" / "<<max<<" current count is: "<<current<<std::endl;
    cond_var.notify_all();//notifies other thread to check their turn arrives.
}


void run(){
    std::unique_lock<std::mutex> ulock (mux);
    ready = true;
    cond_var.notify_all();
}

int main(){
    int threadCount = 15;
    std::thread tArray[15];

    for (int id = 0; id < threadCount ; ++id){
        tArray[id] = std::thread(print_num, id, threadCount);
    }

    std::cout<<"\nRunning "<<threadCount<<" threads in parallel" << std::endl;
    run(); //set the flag.

    for (int id = 0; id < threadCount; ++ id){
        tArray[id].join();
    }

    std::cout<<"Done.";

    return 0;
}