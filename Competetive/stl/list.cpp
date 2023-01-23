#include<bits/stdc++.h>

//non contiGUOus memory.  list has slower traversla than vector but insertion and deletion are faster.
//std::list is doubly linked list.
//std::forward_list is singly linked list.


void displaylist(std::list<int> &lst){
    std::cout<<"content of list is : ";
    for (int &elem: lst){
        std::cout<<elem<<" ";
    }
    std::cout<<std::endl;
}


int main()
{
    std::list<int> lst = {130, 52, 104, 78, 13, 39, 65, 91, 117, 26};

    lst.emplace_back(13);
    displaylist(lst);
    std::cout<<"front of list is "<<lst.front()<<std::endl;
    lst.pop_back();
    displaylist(lst);

    lst.reverse();
    std::cout<<"after reversing list ";
    displaylist(lst);
    std::cout<<std::endl;

    std::list<int> lst2;
    for (int i = 1; i < 11; ++ i)
    {
        lst2.emplace_back(i*22);
    }
    
    lst.merge(lst2);
    for (auto it = lst.begin(); it != lst.end(); ++it){
        std::cout<<*it<<" ";
    }
    return 0;
}