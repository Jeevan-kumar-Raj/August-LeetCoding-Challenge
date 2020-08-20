Day-5 Goat Latin.cpp


/*
A sentence S is given, composed of words separated by spaces. Each word consists of lowercase and uppercase letters only.

We would like to convert the sentence to "Goat Latin" (a made-up language similar to Pig Latin.)

The rules of Goat Latin are as follows:

If a word begins with a vowel (a, e, i, o, or u), append "ma" to the end of the word.
For example, the word 'apple' becomes 'applema'.
 
If a word begins with a consonant (i.e. not a vowel), remove the first letter and append it to the end, then add "ma".
For example, the word "goat" becomes "oatgma".
 
Add one letter 'a' to the end of each word per its word index in the sentence, starting with 1.
For example, the first word gets "a" added to the end, the second word gets "aa" added to the end and so on.
Return the final sentence representing the conversion from S to Goat Latin. 

 

Example 1:

Input: "I speak Goat Latin"
Output: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
Example 2:

Input: "The quick brown fox jumped over the lazy dog"
Output: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"
 

Notes:

S contains only uppercase, lowercase and spaces. Exactly one space between each word.
1 <= S.length <= 150.



*/



// Time:  O(n + w^2), n = w * l,
//                    n is the length of S,
//                    w is the number of words,
//                    l is the average of word lengths
// Space: O(l)

class Solution {
public:
    string toGoatLatin(string S) {
        unordered_set<char> vowel{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        string result, word;
        int count = 0;
        for (int i = 0; i < S.length(); ++i) {
            if (S[i] != ' ') {
                word.push_back(S[i]);
                if (i != S.length() - 1) {
                    continue;
                }
            }
            if (!vowel.count(word.front())) {
                word.push_back(word.front());
                word = word.substr(1);
            }
            word += "ma";
            word += string(++count, 'a');
            result += word;
            result += " ";
            word.clear();
        }
        result.pop_back();
        return result;
    }
};