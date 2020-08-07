Day-6 Find All Duplicates in an Array.cpp


/*
Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]


*/

// Time:  O(n)
// Space: O(1)

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        for (const auto& i : nums) {
            if (nums[abs(i) - 1] < 0) {
                result.emplace_back(abs(i));
            } else {
                nums[abs(i) - 1] *= -1;
            }
        }
        return result;
    }
};
