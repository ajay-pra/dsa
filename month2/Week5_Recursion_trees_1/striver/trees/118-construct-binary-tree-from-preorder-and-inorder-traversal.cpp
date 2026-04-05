// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

#include <bits/stdc++.h>
using namespace std;

// The tree is built by using **preorder to pick the root** 
// and **inorder to split left and right subtrees**. The first element 
// of preorder is the root, and its index in inorder (found using a hashmap) 
// divides the tree into left and right parts. We then recursively construct 
// both subtrees using appropriate index ranges. A base case stops 
// recursion when no elements are left. This approach runs in **O(n) 
// time** due to hashmap lookup and uses **O(n) space** for the map 
// and recursion stack.


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* buildTreeHelper(vector<int>& preorder, int preStart, int preEnd,
                             vector<int>& inorder, int inStart, int inEnd,
                             unordered_map<int, int> &inMap) {

        if (preStart > preEnd || inStart > inEnd) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[preStart]);

        int inRoot = inMap[root->val];
        int leftSize = inRoot - inStart;

        root->left = buildTreeHelper(preorder, preStart + 1, preStart + leftSize,
                                     inorder, inStart, inRoot - 1, inMap);

        root->right = buildTreeHelper(preorder, preStart + leftSize + 1, preEnd,
                                      inorder, inRoot + 1, inEnd, inMap);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inMap;

        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        return buildTreeHelper(preorder, 0, preorder.size() - 1,
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
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder  = {9, 3, 15, 20, 7};

    Solution obj;
    TreeNode* root = obj.buildTree(preorder, inorder);

    cout << "Inorder of constructed tree: ";
    printInorder(root);

    return 0;
}
