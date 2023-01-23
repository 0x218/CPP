//You are a traveller in a 2D grid.  You begin at top left corner and the goal is to reach botton right corner.  You may only move down or right
//[x][][][]
//[][][][]
//[][][][x]

//hint: anopve is a 3x4 grid.  if you move right, you eliminate first colum.  if you move down, you eliminate one row.  this continues until you reach either 0,1 or 1,0 or 0,0 grid 


#include <bits/stdc++.h>

// long gridTravellerBruteForce(const int row, const int col){
//     if(row == 0 || col == 0 ) return 0;
//     if (row == 1 && col == 1) return 1;

//     return (gridTraveller(row-1, col)//moving down
//             + gridTraveller(row, col-1));//moving right
// }


//memoization
std::unordered_map<std::string,int> memo ;

long gridTravellerMemoize(const int row, const int col){
    std::string key = std::to_string(row) + ',' + std::to_string(col);
    
    if(memo.count(key) > 0) return memo.at(key);
    if(row == 0 || col == 0 ) return 0;
    if (row == 1 && col == 1) return 1;

    memo[key] = (gridTravellerMemoize(row-1, col)//moving down
                         + gridTravellerMemoize(row, col-1));//moving right
    return memo[key];
}

int main(){
    std::cout<<"a 1x1 grid travller has "<<gridTravellerMemoize(1,1)<<" ways to reach source to destination\n";
    std::cout<<"a 2x3 grid travller has "<<gridTravellerMemoize(2,3)<<" ways to reach source to destination\n";
    std::cout<<"a 3x3 grid travller has "<<gridTravellerMemoize(3,3)<<" ways to reach source to destination\n";
    std::cout<<"a 5x4 grid travller has "<<gridTravellerMemoize(5,4)<<" ways to reach source to destination\n";
    std::cout<<"a 20x20 grid travller has "<<gridTravellerMemoize(20,20)<<" ways to reach source to destination\n";

    return 0;
}