// https://leetcode.com/problems/same-tree/


/*
Approach (Recursive - DFS):
We compare both trees node by node.
- If both nodes are NULL → they are equal
- If one is NULL → not equal
- If values differ → not equal
- Otherwise, recursively check left and right subtrees

So at every node:
Tree is same = (left subtree same) AND (right subtree same)

Time Complexity: O(n)  -> we visit each node once
Space Complexity: O(h) -> recursion stack (h = height, worst case O(n))
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

        return (isSameTree(p->left, q->left) &&
                isSameTree(p->right, q->right));
    }
};

int main() {
    /*
        Tree 1:            Tree 2:
              1                  1
             / \                / \
            2   3              2   3

        Expected Output: true
    */

    // Tree 1
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    // Tree 2
    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    Solution sol;

    bool ans = sol.isSameTree(p, q);

    if(ans) cout << "Trees are SAME" << endl;
    else cout << "Trees are NOT SAME" << endl;

    return 0;
}