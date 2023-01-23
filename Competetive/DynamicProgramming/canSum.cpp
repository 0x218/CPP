#include <bits/stdc++.h>

// bool CanSum_bruteforce(int targetSum, vector<int> &vec)
// {
//     if (targetSum == 0) return true;
//     if (targetSum < 0) return false;
//     int remainder;

//     for (auto num : vec)
//     {
//         remainder = targetSum - num;
//         if (CanSum_bruteforce(remainder, vec))
//         {
//             return true;
//         }
//     }
//     return false;
// }

bool CanSum_DP(int targetSum, std::vector<int> &vec, std::map<int, bool> &memo) {
    if (memo.find(targetSum) != memo.end()) return memo[targetSum];
    else if (targetSum == 0) return true;
    else if (targetSum < 0) return false;
    else{
        int remainder;

        for (auto i : vec) {
            remainder = targetSum - i;
            if (CanSum_DP(remainder, vec, memo) ){
                memo.emplace(targetSum, true);
                return true;
            }
        }
        memo.emplace(targetSum, false);
    }
    return false;
}



int main()
{
    std::vector<int> v1 = {2, 4};
    std::map<int, bool>memo;
    int sum = 7;

    bool bCallDP = false;
    //if (CanSum_bruteforce(sum, v1)) std::cout << "true\n"; else std::cout << "false\n";
    if (CanSum_DP(sum, v1, memo)) std::cout << "true\n"; else std::cout << "false\n";

    v1 = {5, 3, 4, 7};
    sum = 7;
    //if (CanSum_bruteforce(sum, v1)) std::cout << "true\n"; else std::cout << "false\n";
    if (CanSum_DP(sum, v1, memo)) std::cout << "true\n"; else std::cout << "false\n";

    v1 = {2, 5, 3};
    sum = 8;
    //if (CanSum_bruteforce(sum, v1)) std::cout << "true\n"; else std::cout << "false\n";
    if (CanSum_DP(sum, v1, memo)) std::cout << "true\n"; else std::cout << "false\n";

    v1 = {7, 14};
    sum = 300;
    //if (CanSum_bruteforce(sum, v1)) std::cout << "true\n"; else std::cout << "false\n";
    if (CanSum_DP(sum, v1, memo)) std::cout << "true\n"; else std::cout << "false\n";

    return 0;
}
