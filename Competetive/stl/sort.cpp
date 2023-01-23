#include <bits/stdc++.h>

int main()
{
    int arr[] =  { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };

    int isize = sizeof(arr)/sizeof(arr[0]);

    std::sort(arr, arr + isize);

    std::cout<<"sorted : ";
    for(auto num: arr){
        std::cout<<num<<" ";
    }
    
    std::cout<<"\nbinary_search -ing 7 : " ;
    if (std::binary_search(arr, arr+isize, 7)> 0 )  std::cout<<"match found.\n";
    else std::cout<<"match not found.\n";

    return 0;
}