// https://leetcode.com/problems/maximum-depth-of-binary-tree/


/*
Approach (Recursive - DFS):
We calculate the height (maximum depth) of the binary tree using recursion.
For every node, we recursively find the depth of its left and right subtree,
then return 1 + max(leftDepth, rightDepth).

Base Case:
If node is NULL → depth = 0

Time Complexity: O(n)  -> each node is visited once
Space Complexity: O(h) -> recursion stack (h = height of tree, worst case O(n))
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        return 1 + max(lh, rh);
    }
};

int main() {
    /*
        Tree:
              3
            /   \
           9     20
                /  \
               15   7

        Expected Output: 3
    */

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;

    int depth = sol.maxDepth(root);

    cout << "Maximum Depth of Tree: " << depth << endl;

    return 0;
}