// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// You want to maximize your profit by choosing a single day to buy one stock and choosing a different 
// day in the future to sell that stock.

// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

// Example#1
// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.

// Example#2
// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transactions are done and the max profit = 0.
//==============================================================================================================
#include <bits/stdc++.h>
using namespace std;


int maxProfit(int prices[], int n)
{
    int buy = prices[0], max_profit = 0;
    for (int i = 1; i < n; i++) {
         
        if (buy > prices[i])// Checking for lower buy value
            buy = prices[i];      
        else if (prices[i] - buy > max_profit)// Checking for higher profit
            max_profit = prices[i] - buy;
    }
    return max_profit;
}
 

int main()
{
    //int prices[] = { 7, 1, 5, 6, 4 };
    //int prices[] = {7,6,4,3,1};
    int prices[] ={100, 180, 260, 310, 40, 535, 695};
    int n = sizeof(prices) / sizeof(prices[0]);
    int max_profit = maxProfit(prices, n);
    cout << max_profit << endl;
    return 0;
}
