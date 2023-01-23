#include <bits/stdc++.h>

//each element has to be unique.  values are stored either is ascending or descending.

//NOTE: unordered_set is implemented using a hash table, where keys are hashed into indices of a hash table.  so the insertino is always randomized.
int main()
{
    std::set<int>s1; //default; ascending order
    s1.insert(40);
    s1.insert(30);
    s1.insert(60);
    s1.insert(20);
    s1.insert(50);
    s1.insert(50);//dupli
    s1.insert(10);
 
    std::set<int, std::greater<int> >::iterator itr;
    std::cout << "\nThe set s1 in default (asc) order is : \n";
    for (itr = s1.begin(); itr != s1.end(); itr++) {
        std::cout << *itr << " ";
    }
    std::cout << std::endl;
 
    // remove all elements up to 30 in s2
    std::cout << "\ns2 after removal of elements less than 30 :\n";
    s1.erase(s1.begin(), s1.find(30));
    for (itr = s1.begin(); itr != s1.end(); itr++) {
        std::cout << *itr << " ";
    }
    std::cout<<std::endl;
 
    // lower bound and upper bound for set s1
    std::cout << "s1.lower_bound(20) : \n"<< *s1.lower_bound(20) << std::endl;
    std::cout << "s1.upper_bound(20) : \n"<< *s1.upper_bound(20) << std::endl;
 
   
    std::set<int, std::greater<int>> s2(s1.begin(), s1.end()); //descending order
    std::cout << "\nThe set s2 in descending order is : \n";
    std::set<int>::iterator itr2;
    for (itr2 = s2.begin(); itr2 != s2.end(); itr2++) {
        std::cout << *itr2 << " ";
    }
 
    return 0;
}
