#include <bits/stdc++.h>

void print(std::vector<int>& vec)
{
    for (auto &elem: vec)    std::cout<<elem<<" ";
    std::cout<<std::endl;
}

int main(){
    int arr[] =  {10, 20, 5, 23 ,42 , 15, 32, 31};

    int isize = sizeof(arr)/sizeof(arr[0]);

    std::vector<int> vec (arr, arr+isize);

    for (int i = 0; i< 10 ;++i){
        vec.emplace_back(i*17);
    }

    std::cout<<"capacity of vector "<<vec.capacity()<<std::endl;
    vec.shrink_to_fit();
    std::cout<<"capacity of vector after shrink_to_fit "<<vec.capacity()<<std::endl;

    std::cout<<"sorted : ";
    std::sort(vec.begin(), vec.end());
    print(vec);
    
    std::cout<<"reverse : ";
    std::reverse(vec.begin(), vec.end());
    print (vec);

    std::cout<<"min element : "<<*std::min_element(vec.begin(), vec.end())<<std::endl;
    std::cout<<"max element : "<<*std::max_element(vec.begin(), vec.end())<<std::endl;
    std::cout<<"sum of elem : "<<std::accumulate(vec.begin(), vec.end(), 0)<<std::endl;

    std::cout<<"occurance of 20 : "<<std::count(vec.begin(), vec.end(), 20)<<std::endl;

    std::cout<<"find 20 ";
    if (std::find(vec.begin(), vec.end(), 20) != vec.end()){
        std::cout<<"found 20.\n"; 
    }
    else {
        std::cout<<"20 not found\n";
    }

    is_partitioned(vec.begin(), vec.end(), [](int x)  { return x%2==0; })? std::cout << "Vector is partitioned": std::cout << "Vector is not partitioned";
    std::cout << std::endl;

    std::partition(vec.begin(), vec.end(), [](int x)
    {
        return x%2==0;
         
    });
    std::cout<<"partitioned result: ";
    for (int &x : vec) std::cout << x << " ";
    return 0;
}