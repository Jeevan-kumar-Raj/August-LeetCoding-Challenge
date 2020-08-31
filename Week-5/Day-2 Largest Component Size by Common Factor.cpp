Day-2 Largest Component Size by Common Factor.cpp


/*
Given a non-empty array of unique positive integers A, consider the following graph:

There are A.length nodes, labelled A[0] to A[A.length - 1];
There is an edge between A[i] and A[j] if and only if A[i] and A[j] share a common factor greater than 1.
Return the size of the largest connected component in the graph.

 

Example 1:

Input: [4,6,15,35]
Output: 4

Example 2:

Input: [20,50,9,63]
Output: 2

Example 3:

Input: [2,3,6,7,4,12,21,39]
Output: 8

Note:

1 <= A.length <= 20000
1 <= A[i] <= 100000




*/


// Time:  O(f * n), f is the max number of unique prime factors
// Soace: O(p + n), p is the total number of unique primes

class Solution {
public:
    int largestComponentSize(vector<int>& A) {
        UnionFind union_find(A.size());
        unordered_map<int, int> nodesWithCommonFactor;
        for (int i = 0; i < A.size(); ++i) {
            for (const auto& factor : primeFactors(A[i])) {
                if (!nodesWithCommonFactor.count(factor)) {
                    nodesWithCommonFactor[factor] = i;
                }
                union_find.union_set(nodesWithCommonFactor[factor], i);
            }
         }
        return union_find.max_size();
    }

private:
    vector<int> primeFactors(int i) const {
        vector<int> result;
        int d = 2;
        if (i % d == 0) {
            while (i % d == 0) {
                i /= d;
            }
            result.emplace_back(d);
        }
        d = 3;
        for (d = 3; d * d <= i; d += 2) {
            if (i % d == 0) {
                while (i % d == 0) {
                    i /= d;
                }
                result.emplace_back(d);
            }
        }
        if (i > 2) {
            result.emplace_back(i);
        }
        return result;
    }

    class UnionFind {
        public:
            UnionFind(const int n) : set_(n), size_(n, 1) {
                iota(set_.begin(), set_.end(), 0);
            }

            int find_set(const int x) {
               if (set_[x] != x) {
                   set_[x] = find_set(set_[x]);  // Path compression.
               }
               return set_[x];
            }

            bool union_set(const int x, const int y) {
                int x_root = find_set(x), y_root = find_set(y);
                if (x_root == y_root) {
                    return false;
                }
                set_[min(x_root, y_root)] = max(x_root, y_root);
                size_[max(x_root, y_root)] += size_[min(x_root, y_root)];
                return true;
            }
        
            int max_size() const {
                return *max_element(size_.cbegin(), size_.cend());
            }

        private:
            vector<int> set_;
            vector<int> size_;
    };
};