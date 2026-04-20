// https://leetcode.com/problems/binary-tree-maximum-path-sum/

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
    int maxSum(TreeNode* root, int &ans){
        /*
        This function calculates the maximum path sum using a recursive DFS approach. 
        At each node, we compute the maximum sum we can get from its left and right subtrees 
        (ignoring negative sums by taking max(0, ...)). The potential maximum path sum 
        passing through this node is ls + rs + root->val, which we use to update the global 
        maximum 'ans'. The function then returns the maximum path sum starting from this node 
        and extending to one side (left or right), because in a path we cannot turn back. 
        This ensures that all possible paths in the tree are considered.
        */
        if(root == nullptr) return 0;

        int ls = max(0, maxSum(root->left, ans));
        int rs = max(0, maxSum(root->right, ans));

        ans = max(ans, ls + rs + root->val);

        return max(ls, rs) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        maxSum(root, ans);
        return ans;
    }
};

// 🔹 Driver Code
int main() {
    /*
            10
           /  \
          2   10
         / \    \
        20  1   -25
                 / \
                3   4
    */

    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(2);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(20);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(-25);
    root->right->right->left = new TreeNode(3);
    root->right->right->right = new TreeNode(4);

    Solution obj;
    cout << obj.maxPathSum(root) << endl;  // Output: 42

    return 0;
}