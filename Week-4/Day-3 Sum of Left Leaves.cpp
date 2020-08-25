Day-3 Sum of Left Leaves.cpp


/*
Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.




*/


// Time:  O(n)
// Space: O(h)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return sumOfLeftLeavesHelper(root, false);
    }

private:
    int sumOfLeftLeavesHelper(TreeNode* root, bool is_left) {
        if (!root) {
            return 0;
        }
        if (!root->left && !root->right) {
            return is_left ? root->val : 0;
        }
        return sumOfLeftLeavesHelper(root->left, true) +
               sumOfLeftLeavesHelper(root->right, false);
    }
};