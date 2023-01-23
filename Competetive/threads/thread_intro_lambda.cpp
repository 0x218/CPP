//find sum of even and odd numbers between start to end.
//compile:  g++ -pthread -o thread_intro ./thread_intro.cpp

#include <iostream>
#include <thread>
#include <algorithm>

int main(){

    long lstart = 0, lend = 19000000, lEvenSum = 0, lOddSum = 0;
    
    auto sumofEven = [](long lstart, long lend, long* lsum){
        for (long lc = lstart; lc < lend; ++lc){
            if (lc % 2 == 0) *lsum += lc;
        }
    };

    auto sumOfOdd = [](long lstart, long lend, long* lsum){
        for (long lc = lstart; lc < lend; ++lc){
            if (lc & 1) *lsum += lc;
        }
    };

    std::thread tEven (sumofEven, lstart, lend, &lEvenSum);
    std::thread tOdd (sumOfOdd, lstart, lend, &lOddSum);

    tEven.join();
    tOdd.join();

    std::cout<<"Sum of Even " << lEvenSum <<"\nSum of Odd "<< lOddSum<<std::endl;

    return 0;
}


