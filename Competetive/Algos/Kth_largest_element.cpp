//find K'th larget element in an array
#include <bits/stdc++.h>

int main(){
	std::vector<int> arr = {7, 4, 6, 3, 9, 1};
	int largestK = 2;//find second larget element

	std::sort(arr.begin(), arr.end(), [](const int a, const int b){ return a > b; });

	// for (auto elem: arr)
	// {
	// 	std::cout<<elem<<" ";
	// }
	std::cout<<std::endl;
	std::cout<<"The #"<<largestK<< " largest element is "<<arr[largestK - 1];
	return 0;
}