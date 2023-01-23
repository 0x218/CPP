#include <iostream>
using namespace std;
 
class SortStrategy 
{
    public:
        virtual void sort() const = 0;
};
 
class HeapSort: public SortStrategy
{
    public:
        virtual void sort() const {
            cout << "Heap sort()\n";
        }
};
 
class MergeSort: public SortStrategy 
{
    public:
        virtual void sort() const {
            cout << "Merge sort()\n";
        }
};

// Context
class Collection 
{
    private:
        SortStrategy* m_sort;
        //SearchStragey* m_search;
      
    public:
        Collection(){}
        void set_sort(SortStrategy* s){
            m_sort = s;
        }
  
        void sort() const {
            m_sort->sort();
        }
};
 
 
int main()
{
    HeapSort heap;
    //MergeSort merge;
 
    Collection col;
    col.set_sort(&merge;);
    col.sort();

    return 0;
}
