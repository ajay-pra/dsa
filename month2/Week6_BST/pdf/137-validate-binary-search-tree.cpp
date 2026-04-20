// https://leetcode.com/problems/validate-binary-search-tree/

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool validate(TreeNode* root, long long minVal, long long maxVal) {
        /*
        To check if a binary tree is a BST, we ensure that every node's value lies strictly
        between the allowed min and max values for its position. We pass down the range
        [minVal, maxVal] during recursion. For the left child, maxVal becomes current node's value.
        For the right child, minVal becomes current node's value. If any node violates the constraint,
        we return false. This method guarantees correctness by checking all subtrees.
        */
        if (!root) return true; // empty node is valid
        if (root->val <= minVal || root->val >= maxVal) return false;
        return validate(root->left, minVal, root->val) && 
               validate(root->right, root->val, maxVal);
    }

    bool isValidBST(TreeNode* root) {
        return validate(root, LLONG_MIN, LLONG_MAX);
    }
};

// 🔹 Driver Code
int main() {
    /*
            5
           / \
          3   7
         / \   \
        2   4   8
    */
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(8);

    Solution obj;
    cout << (obj.isValidBST(root) ? "True" : "False") << endl;

    return 0;
}