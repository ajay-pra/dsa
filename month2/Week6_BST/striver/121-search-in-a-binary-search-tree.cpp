// https://leetcode.com/problems/search-in-a-binary-search-tree/

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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr) {
            return root;
        }
        if (root->val == val) return root;

        if (val < root->val)
            return searchBST(root->left, val);
        else
            return searchBST(root->right, val);
    }
};

// Helper function to insert nodes into BST
TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Inorder traversal (for checking)
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    TreeNode* root = nullptr;

    // Creating BST
    vector<int> values = {4, 2, 7, 1, 3};
    for (int val : values) {
        root = insert(root, val);
    }

    cout << "Inorder Traversal of BST: ";
    inorder(root);
    cout << endl;

    Solution sol;
    int target = 2;

    TreeNode* result = sol.searchBST(root, target);

    if (result) {
        cout << "Value found: " << result->val << endl;
        cout << "Subtree Inorder: ";
        inorder(result);
        cout << endl;
    } else {
        cout << "Value not found" << endl;
    }

    return 0;
}