// https://leetcode.com/problems/insert-into-a-binary-search-tree/description/


#include <bits/stdc++.h>
using namespace std;

// The solution inserts a value into a Binary Search Tree 
// using recursion. If the root is null, a new node is 
// created and returned. Otherwise, the value is compared 
// with the current node’s value—if it is smaller, 
// the function recursively inserts the value into 
// the left subtree; if larger, into the right subtree. 
// This process continues until the correct position is 
// found, maintaining the BST property. Finally, the 
// original root is returned after updating the tree 
// links.

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }

        if (val < root->val) {
            root->left = insertIntoBST(root->left, val);
        } else {
            root->right = insertIntoBST(root->right, val);
        }

        return root;
    }
};

// 🔹 Helper function to print BST (Inorder)
void inorder(TreeNode* root) {
    if (!root) return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// 🔹 Driver Code
int main() {
    Solution obj;
    TreeNode* root = nullptr;

    // Insert values
    vector<int> values = {5, 3, 7, 2, 4, 6, 8};

    for (int val : values) {
        root = obj.insertIntoBST(root, val);
    }

    cout << "Inorder Traversal of BST: ";
    inorder(root);

    return 0;
}