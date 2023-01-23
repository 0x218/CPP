//find sum of even and odd numbers between start to end.
//compile:  g++ -pthread -o thread_intro ./thread_intro.cpp

#include <iostream>
#include <thread>
#include <algorithm>

void sumofEven(long lstart, long lend, long* lsum){
    //lsum = 0;

    for (long lc = lstart; lc < lend; ++lc){
        if (lc % 2 == 0) *lsum += lc;
    }
}

void sumofOdd(long lstart, long lend, long* lsum){
    //lsum = 0;
    for (long lc = lstart; lc < lend; ++lc){
        if (lc % 2 != 0) *lsum += lc;
    }
}

int main(){

    long lstart = 0, lend = 19000000, lEvenSum = 0, lOddSum = 0;

    std::thread tEven (sumofEven, lstart, lend, &(lEvenSum));
    std::thread tOdd (sumofOdd, lstart, lend, &(lOddSum));

    tEven.join();
    tOdd.join();

    std::cout<<"Sum of Even " << lEvenSum <<"\nSum of Odd "<< lOddSum<<std::endl;

    return 0;
}


