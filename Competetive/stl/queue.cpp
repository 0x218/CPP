#include <bits/stdc++.h>

//queues are encapsulated object of deque or list.

void showq(std::queue<int> gq)
{
    while (!gq.empty()) {
        std::cout << '\t' << gq.front();
        gq.pop();
    }
    std::cout << '\n';
}
  
// Driver Code
int main()
{
    std::queue<int> que {{23, 26,126,75,97,234,74,11,2}};   
    que.push(27);

  
    std::cout << "The queue  is : ";
    showq(que);
  
    std::cout << "\ngquiz.size() : " << que.size();
    std::cout << "\ngquiz.front() : " << que.front();
    std::cout << "\ngquiz.back() : " << que.back();
  
    std::cout << "\ngquiz.pop() : ";
    que.pop();
    showq(que);
  
    return 0;
}
