Day-7 Longest Palindrome.cpp

/*
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.


*/



class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> counts;
        for(char c: s) counts[c]++;
        
        int result = 0;
        bool odd_found = false;
        for(auto& c: counts){
            if(c.second % 2 == 0) result += c.second;
            else{
                odd_found = true;
                result += c.second - 1;
            }
        }
        if(odd_found) result++;
        return result;
    }
};
