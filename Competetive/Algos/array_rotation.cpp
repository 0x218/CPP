#include <bits/stdc++.h>

//arr[] = {1, 2, 3, 4, 5, 6, 7}
//poistion: d = 2
//Output: 3 4 5 6 7 1 2

void RotateArray(std::array<int, 7> &arr, int isize, const int rotatePos){
    int iStart = 0;
    int rotate = rotatePos;
    int temp ;
    int i;
    while(rotate >= 0){
        temp = arr[0];//0th
        for (i = 0; i < (isize - 1); ++ i){
            arr[i] = arr[i+1];
        }
        arr[i] = temp;
        --rotate;
    }
}

int main(){
    std::array<int,7> arr = {1, 2, 3, 4, 5, 6, 7};
    int rotatePos = 2;

    RotateArray(arr, arr.size(), rotatePos);
    for (auto &elem : arr){
        std::cout<<elem<<" ";
    }
    return 0;
}