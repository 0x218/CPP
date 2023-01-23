#include <bits/stdc++.h>


//first element of the queue is either gretest (default) or smallest among others.

void showpq(std::priority_queue<int> pq)
{
    while (!pq.empty()) {
        std::cout << '\t' << pq.top();
        pq.pop();
    }
    std::cout << '\n';
}


void show_ascending_pq(
    std::priority_queue<int, 
                        std::vector<int>, 
                        std::greater<int> 
                        > pq)
{
    while (!pq.empty()) {
        std::cout << '\t' << pq.top();
        pq.pop();
    }
    std::cout << '\n';
}


int main()
{
    std::priority_queue<int> pqueue; //default ascending order
    std::priority_queue<int, std::vector<int>, std::greater<int>> asc_queue;

    pqueue.push(10);
    pqueue.push(5);
    pqueue.push(30);
    pqueue.push(20);
    pqueue.push(1);
    pqueue.emplace(23);
  
    
    asc_queue.push(10);
    asc_queue.push(5);
    asc_queue.push(30);
    asc_queue.push(20);
    asc_queue.push(1);
    asc_queue.emplace(23);


    std::cout << "The default (desc) priority queue is : ";
    showpq(pqueue);
    std::cout << "pqueue.size() : " << pqueue.size()<<std::endl;
    std::cout << "pqueue.top() : " << pqueue.top()<<std::endl;
    std::cout << "pqueue.pop() : ";
    pqueue.pop();
    showpq(pqueue);


    std::cout << "\nThe ascending priority queue is : ";
    show_ascending_pq(asc_queue);
    std::cout << "greater queue.size() : " << asc_queue.size()<<std::endl;
    std::cout << "greater queue.top() : " << asc_queue.top()<<std::endl;
    std::cout << "greater queue.pop() : ";
    asc_queue.pop();
    show_ascending_pq(asc_queue);

    return 0;
}