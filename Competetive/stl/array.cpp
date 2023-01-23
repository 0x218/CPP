#include <bits/stdc++.h>

//array class knew its size.  it has at(), get() and [] operators.

int main()
{
    // Initializing the array elements
    std::array<int,6> ar = {1, 2, 3, 4, 5, 6};
 
    // Printing array elements using at()
    std::cout << "The array elements are (using at()) : ";
    for ( int i=0; i<6; i++){
        std::cout << ar.at(i) << " ";
    }
    std::cout << std::endl;
 
    // Printing array elements using get()
    std::cout << "The array elements are (using get()) : ";
    for ( int i=0; i<6; i++){
        std::cout << std::get<0>(ar) << " " ;
    }
    std::cout << std::endl;
 
    // Printing array elements using operator[]
    std::cout << "The array elements are (using operator[]) : ";
    for ( int i=0; i<6; i++){
        std::cout << ar[i] << " ";
    }
    std::cout << std::endl;
 
    std::cout << "First element of array is : "<< ar.front()<<std::endl;
    std::cout << "The number of array elements is : " << ar.size() << std::endl;
    std::cout << "Maximum elements array can hold is : "<< ar.max_size() << std::endl;

    return 0;
 
}