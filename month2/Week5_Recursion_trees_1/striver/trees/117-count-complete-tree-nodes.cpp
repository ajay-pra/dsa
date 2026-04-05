#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

// We simply traverse the entire binary tree using 
// DFS (recursion). For every node, we count 1 and 
// recursively count nodes in the left and right 
// subtrees. This ensures all nodes are visited.

// Time Complexity: O(N)
// Space Complexity: O(H)

// -------------------- BRUTE FORCE --------------------
int countNodesBrute(TreeNode* root) {
    if (root == NULL) return 0;
    return 1 + countNodesBrute(root->left) + countNodesBrute(root->right);
}

// We use the property of a complete binary tree. 
// For each node, we calculate the leftmost height 
// and rightmost height. If both heights are equal, 
// the subtree is a perfect binary tree, and we can 
// directly compute the number of nodes using the 
// formula 2^h-1. If not, we recursively count nodes 
// in left and right subtrees.

// Time Complexity: O(log² N)
// Space Complexity: O(log N)

// -------------------- OPTIMIZED --------------------
int findHeightLeft(TreeNode* node) {
    int height = 0;
    while (node) {
        height++;
        node = node->left;
    }
    return height;
}

int findHeightRight(TreeNode* node) {
    int height = 0;
    while (node) {
        height++;
        node = node->right;
    }
    return height;
}

int countNodesOptimized(TreeNode* root) {
    if (root == NULL) return 0;

    int lh = findHeightLeft(root);
    int rh = findHeightRight(root);

    // perfect binary tree
    if (lh == rh) {
        return (1 << lh) - 1;
    }

    return 1 + countNodesOptimized(root->left) + countNodesOptimized(root->right);
}


// -------------------- DRIVER CODE --------------------
int main() {
    /*
            1
          /   \
         2     3
        / \   /
       4   5 6
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    cout << "Brute Force Count: " << countNodesBrute(root) << endl;
    cout << "Optimized Count: " << countNodesOptimized(root) << endl;

    return 0;
}