// https://leetcode.com/problems/kth-smallest-element-in-a-bst/submissions/1969414955/

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = right = nullptr;
    }
};
// The kth smallest element in a BST can be found 
// using inorder traversal, which visits nodes in sorted 
// order (left → root → right). By storing the traversal 
// in a vector, the kth smallest element is simply the 
// element at index k-1. This approach has a time complexity 
// of O(N) since all nodes are visited, and space complexity 
// of O(N) for storing the traversal. An optimized approach 
// can reduce space to O(H) by stopping traversal early 
// once the kth element is found.

// Insert into BST (helper)
TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Inorder traversal (LNR)
void inorder(TreeNode* root, vector<int>& traversal) {
    if (!root) return;
    inorder(root->left, traversal);
    traversal.push_back(root->val);
    inorder(root->right, traversal);
}

// kth smallest
int kthSmallest(TreeNode* root, int k) {
    vector<int> traversal;
    inorder(root, traversal);
    return traversal[k - 1];
}

int main() {
    TreeNode* root = nullptr;

    // Hardcoded input
    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    for (int x : arr) {
        root = insert(root, x);
    }

    int k = 3;

    cout << "Kth Smallest Element: " << kthSmallest(root, k) << endl;

    return 0;
}