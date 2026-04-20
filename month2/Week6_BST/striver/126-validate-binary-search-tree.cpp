// https://leetcode.com/problems/validate-binary-search-tree/

#include <bits/stdc++.h>
using namespace std;


//  This approach checks whether a binary tree satisfies the 
// Binary Search Tree property by maintaining a valid 
// range (min, max) for each node. Initially, the root 
// can take any value between -∞ and +∞. As we move left, 
// the maximum allowed value becomes the current node’s 
// value, and as we move right, the minimum allowed value 
// becomes the current node’s value. If any node violates 
// this constraint (i.e., its value is not strictly between 
// min and max), the tree is not a BST. This ensures that 
// all nodes—not just immediate children—follow BST rules.

// TC - O(n)
// SC - O(h)

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
    bool validate(TreeNode* root, long long min, long long max){
        if(root == nullptr) return true;
        if(root->val <= min || root->val >= max) return false;
        return (validate(root->left, min, root->val) &&
                validate(root->right, root->val, max));
    }

    bool isValidBST(TreeNode* root) {
        return validate(root, LLONG_MIN, LLONG_MAX);
    }
};

int main() {
    /*
            5
           / \
          3   7
         / \ / \
        2  4 6  8
    */

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    Solution obj;
    if(obj.isValidBST(root)) {
        cout << "Valid BST" << endl;
    } else {
        cout << "Not a BST" << endl;
    }

    return 0;
}