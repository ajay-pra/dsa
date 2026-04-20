// https://leetcode.com/problems/invert-binary-tree/

/*
Approach (Recursive - DFS):
We recursively visit each node and swap its left and right child pointers.
Each node handles its own swap, and recursion ensures all nodes are covered.

Time Complexity: O(n)  -> we visit every node once
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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return nullptr;

        // swap children
        swap(root->left, root->right);

        // recurse on subtrees
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};



/*
Approach (Iterative - BFS):
We use a queue to perform level order traversal.
At each node, we swap its left and right children, then push them into the queue.
This ensures every node is processed level by level.

Time Complexity: O(n)  -> each node processed once
Space Complexity: O(n) -> queue can store up to n nodes in worst case
*/


class Solution2 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            // swap children
            swap(curr->left, curr->right);

            // push children
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }

        return root;
    }
};

// Helper: Inorder traversal
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    /*
        Tree:
              4
            /   \
           2     7
          / \   / \
         1   3 6   9
    */

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    Solution sol;

    cout << "Inorder before invert: ";
    inorder(root);
    cout << endl;

    root = sol.invertTree(root);

    cout << "Inorder after invert: ";
    inorder(root);
    cout << endl;

    return 0;
}