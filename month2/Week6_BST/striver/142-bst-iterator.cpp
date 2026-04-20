// https://leetcode.com/problems/binary-search-tree-iterator/

#include <bits/stdc++.h>
using namespace std;

// This approach uses the property of a Binary Search Tree (BST) 
// where inorder traversal gives sorted order. We perform an inorder 
// traversal of the tree and store all node values in a vector. 
// Then, we simulate the iterator using an index that moves forward 
// on each next() call. The hasNext() function checks whether more 
// elements are available in the vector.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

class BSTIterator {
public:
    int index = -1;
    vector<int> values;

    void inorder(TreeNode* root) {
        if (root == nullptr) return;
        inorder(root->left);
        values.push_back(root->val);
        inorder(root->right);
    }

    BSTIterator(TreeNode* root) {
        inorder(root);
    }
    
    int next() {
        return values[++index];
    }
    
    bool hasNext() {
        return index + 1 < values.size();
    }
};

// -------- Driver Code --------
int main() {
    /*
            5
          /   \
         3     7
        / \   / \
       2   4 6   8
    */

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    BSTIterator* obj = new BSTIterator(root);

    cout << "BST Iteration: ";
    while (obj->hasNext()) {
        cout << obj->next() << " ";
    }

    return 0;
}