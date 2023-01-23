#include <bits/stdc++.h>


/*An unordered_set is implemented using a hash table where keys are hashed into indices -
of a hash table so that the insertion is always randomized. All operations on the unordered_set -
takes constant time O(1) on an average which can go up to linear time O(n) in worst case.

Set is an ordered sequence of unique keys whereas in unordered_set key can be stored in any order, so unordered.

*/
struct Student{
    int sId;
    std::string sName;
};


//generate hash based on Id
class hashWithStudentId{
    public:
        size_t operator()(const Student &stud) const {
            return std::hash<int>()(stud.sId);
        }
};

//generate comparator based on Id
class compareToStudentId{
    public:
        bool operator == (const Student& stud1, const Student& stud2) const {
            if(stud1.sId == stud2.sId){
                return true;
            }
            return false;
        }
};

//generate comparator based on name
class compareToStudentName{
    public:
        bool operator == (const Student& stud1, const Student& stud2) const {
            if(stud1.sName == stud2.sName){
                return true;
            }
            return false;
        }
};

int main() {
    //custom defined hash and comparision.
    std::unordered_set<Student, hashWithStudentId, compareToStudentId> student;
    int sId = 0;
    std::string sName;
    for(int i = 0 ;i < 5; i++){
        std::cout<<"Enter student name : ";
        std::cin>>sName;
        std::cout<<"Enter student Id : ";
        std::cin>>sId;
        
        student.insert({sId, sName});
    }
    std::cout<<std::endl;
    for(auto stud : student){
        std::cout<<stud.sId<<", "<<stud.sName<<std::endl;
    }
    return 0;
}
