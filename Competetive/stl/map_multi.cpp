#include <bits/stdc++.h>

//multimap can have the same key.  multimap keeps all the keys in sorted order always.
void print_map(std::multimap<int, int> &mmap){
   std::map<int, int>::iterator itr;
    for(itr = mmap.begin(); itr != mmap.end(); ++itr){
        std::cout<<itr->first<< " " <<itr->second<<std::endl;
    }
}

int main()
{
    std::multimap<int, int> mmap;
    mmap.insert(std::pair<int, int> (2,30));
    mmap.insert(std::pair<int, int>(1, 40));
    mmap.insert(std::pair<int, int>(6, 10));
    mmap.insert(std::pair<int, int>(3, 60));
    mmap.insert(std::pair<int, int>(6, 50));
    mmap[4]=21;
    mmap.emplace(5, 35);

    print_map(mmap);
    mmap.erase(mmap.begin(), mmap.find(6));
    std::cout<<"after deleting 6 \n";
    print_map(mmap);

    return 0;
}