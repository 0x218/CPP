#include <bits/stdc++.h>

//unlike std::set, multiset allows duplicates.  values are stored either is ascending or descending.
int main()
{
    // empty multiset container
    std::multiset<int, std::greater<int> > gquiz1;
 
    // insert elements in random order
    gquiz1.insert(40);
    gquiz1.insert(30);
    gquiz1.insert(60);
    gquiz1.insert(20);
    gquiz1.insert(50);
    gquiz1.insert(50);//dupli
    gquiz1.insert(10);
    gquiz1.insert(50);
 
    // printing multiset 
    std::multiset<int, std::greater<int> >::iterator itr;
    std::cout << "\nThe multiset gquiz1 is : \n";
    for (itr = gquiz1.begin(); itr != gquiz1.end(); ++itr) {
        std::cout << *itr << " ";
    }
    std::cout << std::endl;

    //delete one value (even if there are duplicates)
    std::cout << "\nResult after multiset.erase(multiset.find(50)) : \n";
    gquiz1.erase(gquiz1.find(50));
    for (itr = gquiz1.begin(); itr != gquiz1.end(); ++itr) {
        std::cout << *itr << " ";
    }
    std::cout<<std::endl;

    std::cout << "\nResult after multiset.erase(50) : \n";
    gquiz1.erase(50);
    for (itr = gquiz1.begin(); itr != gquiz1.end(); ++itr) {
        std::cout << *itr << " ";
    }
    std::cout<<std::endl;


    return 0;
}