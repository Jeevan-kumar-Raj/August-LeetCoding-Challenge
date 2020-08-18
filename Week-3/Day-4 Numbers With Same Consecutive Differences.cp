Day-4 Numbers With Same Consecutive Differences.cpp

/*
Return all non-negative integers of length N such that the absolute difference between every two consecutive digits is K.

Note that every number in the answer must not have leading zeros except for the number 0 itself. For example, 01 has one leading zero and is invalid, but 0 is valid.

You may return the answer in any order.

 

Example 1:

Input: N = 3, K = 7
Output: [181,292,707,818,929]
Explanation: Note that 070 is not a valid number, because it has leading zeroes.
Example 2:

Input: N = 2, K = 1
Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]
 

Note:

1 <= N <= 9
0 <= K <= 9




*/



// Time:  O(2^n)
// Space: O(2^n)

class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> curr(10);
        iota(curr.begin(), curr.end(), 0);
        for (int i = 0; i < N - 1; ++i) {
            vector<int> next;
            for (const auto& x : curr) {
                int y = x % 10;
                if (x > 0 && y + K < 10) {
                    next.emplace_back(x * 10 + y + K);
                }
                if (x > 0 && K > 0 && y - K >= 0) {
                    next.emplace_back(x * 10 + y - K);
                }
            }
            curr = move(next);
        }
        return curr;
    }
};