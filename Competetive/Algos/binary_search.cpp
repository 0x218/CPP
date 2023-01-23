//NOTE: Binary search is run upon SORTED array.
//step1: Divide the array into half
//step2: Search whether the search_element is less than mid element;
//step3.a:  if the search_element is > mid element, ignore the first half and consider the second half for search.
//step3.b: if the search _emlment is less than mid element, ignore the second half 
//step4: go to step1.


#include <iostream>

int binarySearch(int *arr, const int arr_size, const int search_num){
    int low = 0, high = arr_size, mid = 0;

    while (low <= high){
        mid = (low + high)/2;
        if (search_num == arr[mid]) return mid;
        if (search_num < arr[mid]){
            high = mid;
        }else{
            low = mid+1;
        }
    }
    return -1;
}
int main(){
    int arr[]= {1,5, 25, 35,66, 123, 212, 421, 422, 592};
    int search_num1 = 421, search_num2 = 25, search_num3 = 1000;

    std::cout<<search_num1<< " is at index "<< binarySearch(arr, 9, search_num1) <<std::endl;
    std::cout<<search_num2<< " is at index "<< binarySearch(arr, 9, search_num2) <<std::endl;
    std::cout<<search_num3<< " is at index "<< binarySearch(arr, 9, search_num3) <<std::endl;

}