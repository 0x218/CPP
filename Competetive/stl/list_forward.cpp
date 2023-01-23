#include<bits/stdc++.h>

//singly linked list, faster than others.  cannot back travel.  keeps track of only next location.


int main()
{
    std::forward_list<int> fwlst = {130, 52, 104, 78, 13, 39, 65, 91, 117, 26};

    fwlst.emplace_front(13);
    fwlst.pop_front();

    std::forward_list<int>::iterator ptr;
    // starts insertion from second position
    ptr = fwlst.insert_after(fwlst.begin(), { 1, 2, 3 });

    for (auto it = fwlst.begin(); it != fwlst.end(); ++it){
        std::cout<<*it<<" ";
    }

    fwlst.remove_if([](int x) { return x > 120; });
    return 0;
}