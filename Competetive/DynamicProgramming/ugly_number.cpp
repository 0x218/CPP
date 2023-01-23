#include <bits/stdc++.h>

using namespace std;

//Ugly numbers are numbers whose only prime factors are 2, 3 or 5. The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, …'
//Question: Given a number n, find n't ugly number


int maxDivide(int a, int b)//This function divides greatest divisible power of b
{
    while (a % b == 0)
        a = a / b;
          
    return a;
}
  
int isUgly(int no)
{
    //divide the number by greatest divisible powers of 2, 3 and 5, if the number becomes 1 then it is an ugly number otherwise not.
    no = maxDivide(no, 2);
    no = maxDivide(no, 3);
    no = maxDivide(no, 5);
  
    return (no == 1) ? 1 : 0;
}
  
int getNthUglyNo(int n)
{
    int i = 1;
    int count = 1; //Ugly number count

    while (n > count) //Check for all integers until ugly count becomes n
    {
        i++;
        if (isUgly(i)){
            count++;
        }
    }
    return i;
}
  

int main()
{
    unsigned num = getNthUglyNo(150);
    cout << "150th ugly no. is " << num;
    return 0;
}