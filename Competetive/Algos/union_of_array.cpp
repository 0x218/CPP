#include <iostream>
#include <unordered_set>
#include <algorithm>

using UOS = std::unordered_set<int>;

UOS UnionIt(const int* arr1, int arr1_size, const int* arr2, int arr2_size){
    UOS uoset;
    for (int i = 0; i< arr1_size; ++i){
        uoset.insert(arr1[i]);
    }

    for (int i = 0; i< arr2_size; ++i){
        uoset.insert(arr2[i]);
    }
    return uoset;
}

int main()
{
    int arr1[6]={3, 324, 13,512, 532,3};
    int arr2[4]={23, 53, 23, 3};

    int n = sizeof(arr1)/sizeof(arr1[0]);
    std::sort(arr1, arr1 + n);
    for (int i = 0; i < 6; ++i) {std::cout<<arr1[i]<<" "; }
    std::cout<<std::endl;
    
    //op: 3, 324, 13, 512, 532, 53, 23.
    UOS ret = UnionIt(arr1, 6, arr2, 4);

    for (auto elem : ret){
        std::cout<<elem<<" ";
    }
    return 0;
}