#include <bits/stdc++.h>


/*
unordered_map is an associated container, implemented using Hash Table.
For every key, a hash function is computed and value is stored at that hash entry. 

*/

struct Person {
    std::string first, last;
 
    Person(std::string f, std::string l)
    {
        first = f;
        last = l;
    }
 
    // Match both first and last names in case of collisions.
    bool operator==(const Person& p) const
    {
        return first == p.first && last == p.last;
    }
};
 
class MyHashFunction {
public:
 
    // Use sum of lengths of first and last names as hash function.
    size_t operator()(const Person& p) const
    {
        return p.first.length() + p.last.length();
    }
};


int main()
{
    std::unordered_map<Person, int, MyHashFunction> um;
    
    std::cout<<"Enter first and last name of 5 persons : "<<std::endl;
    for (int i = 1; i <= 5 ; i++)
    {
        std::string fN, lN;
        int iD = i * 100;
        std::cout<<"Person id : " << iD <<std::endl;
        std::cout<<"enter first name : ";
        std::cin>>fN;
        std::cout<<"enter last name : ";
        std::cin>>lN;
        
        Person tmp = Person(fN, lN);
        um[ tmp ] = iD;
    }

    for (auto e : um) {
        std::cout <<e.first.first << ", " << e.first.last<< " = > " << e.second << '\n';
    }
 
    return 0;
}
