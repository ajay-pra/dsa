// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* buildTreeHelper(vector<int>& postorder, int postStart, int postEnd,
                             vector<int>& inorder, int inStart, int inEnd,
                             unordered_map<int, int> &inMap) {

        if (postStart > postEnd || inStart > inEnd) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(postorder[postEnd]);

        int inRoot = inMap[root->val];
        int leftSize = inRoot - inStart;

        root->left = buildTreeHelper(postorder, postStart, postStart + leftSize - 1, inorder, inStart, inRoot - 1, inMap);

        root->right = buildTreeHelper(postorder, postStart + leftSize, postEnd - 1, inorder, inRoot + 1, inEnd, inMap);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        unordered_map<int, int> inMap;

        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        return buildTreeHelper(postorder, 0, postorder.size() - 1,
                               inorder, 0, inorder.size() - 1, inMap);
    }
};

// 🔹 Utility: Print Inorder (to verify)
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

// 🔹 Driver Code
int main() {
    vector<int> inorder   = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    Solution obj;
    TreeNode* root = obj.buildTree(inorder, postorder);

    cout << "Inorder of constructed tree: ";
    printInorder(root);

    return 0;
}