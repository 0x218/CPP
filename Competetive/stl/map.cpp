#include <bits/stdc++.h>

//each element has a key and a value.  key must be unique.

//NOTE: multimap can have the same key.  multimap keeps all the keys in sorted order always.
int main()
{
  
    // empty map container
    std::map<int, int> gquiz1;
  
    // insert elements in random order
    gquiz1.insert(std::pair<int, int>(1, 40));
    gquiz1.insert(std::pair<int, int>(4, 20));
    gquiz1.insert(std::pair<int, int>(6, 50));
    gquiz1.insert(std::pair<int, int>(2, 30));
    gquiz1.insert(std::pair<int, int>(3, 60));
    gquiz1.insert(std::pair<int, int>(5, 50));
    gquiz1[7]=10;     // another way of inserting a value in a map
     
  
    // printing map gquiz1
    std::map<int, int>::iterator itr;
    std::cout << "\nThe map gquiz1 is : \n\tKEY\tELEMENT\n";
    for (itr = gquiz1.begin(); itr != gquiz1.end(); ++itr) {
        std::cout << '\t' << itr->first << '\t' << itr->second<< '\n';
    }
    std::cout << std::endl;
  
    // remove all elements up to key=3 in gquiz1
    std::cout << "\ngquiz1 after removal of elements less than key=3 : \n";
    std::cout << "\tKEY\tELEMENT\n";
    gquiz1.erase(gquiz1.begin(), gquiz1.find(3));
    for (itr = gquiz1.begin(); itr != gquiz1.end(); ++itr) {
        std::cout << '\t' << itr->first << '\t' << itr->second<< '\n';
    }
  
    // lower bound and upper bound for map gquiz1 key = 5
    std::cout << "gquiz1.lower_bound(5) : \tKEY = ";
    std::cout << gquiz1.lower_bound(5)->first << '\t';
    std::cout << "\tELEMENT = " << gquiz1.lower_bound(5)->second<< std::endl;
    std::cout << "gquiz1.upper_bound(5) : \tKEY = ";
    std::cout << gquiz1.upper_bound(5)->first << '\t';
    std::cout << "\tELEMENT = " << gquiz1.upper_bound(5)->second<< std::endl;
  
    //gquiz1.clear(); //deletes all values from map

    return 0;
}
