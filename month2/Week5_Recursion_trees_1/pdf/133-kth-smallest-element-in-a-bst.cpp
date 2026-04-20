// https://leetcode.com/problems/kth-smallest-element-in-a-bst/


/**
 * 🔹 Approach (Kth Smallest in BST)
 * 
 * In a Binary Search Tree (BST), inorder traversal gives elements 
 * in sorted (ascending) order.
 * 
 * So, we:
 * 1. Perform inorder traversal
 * 2. Store elements in a vector
 * 3. Return the (k-1)th index (since vector is 0-based)
 * 
 * ⏱️ Time Complexity: O(N)
 *    - We traverse all nodes
 * 
 * 💾 Space Complexity: O(N)
 *    - Vector stores all elements
 *    - Recursion stack up to O(H)
 */

#include <bits/stdc++.h>
using namespace std;

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
    // Inorder traversal
    void func(TreeNode* &root, vector<int> &traversal){
        if(root == nullptr){
            return;
        }

        func(root->left, traversal);      // left
        traversal.push_back(root->val);   // root
        func(root->right, traversal);     // right
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> traversal;
        func(root, traversal);
        return traversal[k-1];   // kth smallest
    }
};


int main() {
    /*
            5
           / \
          3   6
         / \
        2   4
       /
      1
    */

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);

    Solution obj;

    int k = 3;
    cout << "Kth Smallest: " << obj.kthSmallest(root, k) << endl;

    return 0;
}