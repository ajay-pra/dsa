// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/


#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// The Lowest Common Ancestor (LCA) in a binary tree is solved using a 
// **DFS (Depth-First Search) recursive approach**. The idea is to traverse 
// the tree and at each node check whether the target nodes `p` and `q` 
// exist in its left and right subtrees. If both left and right recursive 
// calls return non-null, it means one node is found in each subtree, 
// so the current node is the LCA. If only one side returns non-null, 
// we propagate that result upward, as it means both nodes are located 
// in that subtree. If the current node itself matches `p` or `q`, 
// we return it. This works because the LCA is the **first node where 
// the paths to `p` and `q` diverge**. The approach runs in **O(N)** 
// time with **O(H)** recursion stack space.

// TC - O(n)
// SC - O(H) Balanced tree: O(log N) Skewed tree: O(N)

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // base case
        if (root == nullptr || root == p || root == q) {
            return root;
        }

        // recursive calls
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // if both sides return non-null → LCA
        if (left != nullptr && right != nullptr) {
            return root;
        }

        // otherwise propagate non-null
        return (left != nullptr) ? left : right;
    }
};


// 🔥 Helper to find node pointer by value (for driver only)
TreeNode* findNode(TreeNode* root, int val) {
    if (!root) return nullptr;
    if (root->val == val) return root;

    TreeNode* left = findNode(root->left, val);
    if (left) return left;

    return findNode(root->right, val);
}


// 🔥 Driver Code
int main() {
    /*
            3
           / \
          5   1
         / \ / \
        6  2 0  8
          / \
         7   4
    */

    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(5);
    root->right = new TreeNode(1);

    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);

    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    int p_val = 6;
    int q_val = 4;

    TreeNode* p = findNode(root, p_val);
    TreeNode* q = findNode(root, q_val);

    Solution obj;
    TreeNode* lca = obj.lowestCommonAncestor(root, p, q);

    if (lca) {
        cout << "LCA of " << p_val << " and " << q_val << " is: " << lca->val << endl;
    } else {
        cout << "LCA not found" << endl;
    }

    return 0;
}