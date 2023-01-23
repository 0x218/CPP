#include <bits/stdc++.h>


long memorize[100] = {0};

long fibonacci(int num){
    if(memorize[num] == 0)
    {
        if (num <= 1) {
            memorize[num] = num;
        }
        else{
            memorize[num] = (fibonacci(num-1) + fibonacci(num-2));
        }
    }
    return memorize[num];
}


int main(){
    int fib;
    std::cout<<"Enter number to find its fibonacci ";
    std::cin>>fib;

    std::cout<<"Result of fibonacci "<<fib<<" is "<<fibonacci(fib);

    return 0;
}