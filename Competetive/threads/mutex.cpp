#include <iostream>
#include <thread>
#include <mutex>


int netBalance = 0;
std::mutex mux_netBalance;

void addMoney(){
    for(int l = 0; l < 50000; ++l) {
        mux_netBalance.lock();
        ++netBalance;
        mux_netBalance.unlock();
    }
}


int main(){
    std::thread tBanker1(addMoney);
    std::thread tBanker2(addMoney);

    tBanker1.join();
    tBanker2.join();

    std::cout<<"Net balance is "<<netBalance;

    return 0;
}