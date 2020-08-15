Day-6 Iterator for Combination.cpp

/*
Design an Iterator class, which has:

A constructor that takes a string characters of sorted distinct lowercase English letters and a number combinationLength as arguments.
A function next() that returns the next combination of length combinationLength in lexicographical order.
A function hasNext() that returns True if and only if there exists a next combination.
 

Example:

CombinationIterator iterator = new CombinationIterator("abc", 2); // creates the iterator.

iterator.next(); // returns "ab"
iterator.hasNext(); // returns true
iterator.next(); // returns "ac"
iterator.hasNext(); // returns true
iterator.next(); // returns "bc"
iterator.hasNext(); // returns false
 

Constraints:

1 <= combinationLength <= characters.length <= 15
There will be at most 10^4 function calls per test.
It's guaranteed that all calls of the function next are valid.



*/


class CombinationIterator {
    string s;
    queue<string> q;
    
    void getCombination(int start, int length, string txt){
        if(length == 0){
            q.push(txt);
            return;
        }
        
        for(int i = start; i <= s.length() - length; ++i)
            getCombination(i+1, length-1, txt + s[i]);
    }
public:
    CombinationIterator(string characters, int combinationLength) {
        s = characters;
        string txt = "";
        getCombination(0, combinationLength, txt);
    }
    
    string next() {
        string str = q.front();
        q.pop();
        return str;
    }
    
    bool hasNext() {
        return !q.empty();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
