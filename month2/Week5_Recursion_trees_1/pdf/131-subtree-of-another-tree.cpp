// https://leetcode.com/problems/subtree-of-another-tree/

/*
Approach (Recursive - DFS + Tree Matching):
We traverse the main tree (root). At every node, we check:
- If the subtree starting from this node is identical to subRoot (using isSameTree)
- If yes → return true
- Otherwise → recursively search in left and right subtree

So each node asks:
"Can I be the starting point of subRoot?"

Time Complexity: O(n * m)
n = nodes in root, m = nodes in subRoot
(In worst case, we compare subRoot at every node of root)

Space Complexity: O(h)
h = height of tree (recursion stack), worst case O(n)
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr) return true;
        if(p == nullptr || q == nullptr) return false;
        if(p->val != q->val) return false;

        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr) return false;

        if(isSameTree(root, subRoot)) return true;

        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};

int main() {
    /*
        Main Tree:
              3
             / \
            4   5
           / \
          1   2

        SubTree:
            4
           / \
          1   2

        Expected Output: true
    */

    // Main Tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);

    // SubTree
    TreeNode* subRoot = new TreeNode(4);
    subRoot->left = new TreeNode(1);
    subRoot->right = new TreeNode(2);

    Solution sol;

    bool ans = sol.isSubtree(root, subRoot);

    if(ans) cout << "Subtree exists" << endl;
    else cout << "Subtree does NOT exist" << endl;

    return 0;
}