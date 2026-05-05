// https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
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
    void func(TreeNode* root, int maxSoFar, int &count){
        if(root == nullptr) return;

        /*
        A node is considered a good node if its value is greater than or equal to the maximum value 
        encountered along the path from the root to that node. To solve this, we use DFS traversal 
        and carry a variable maxSoFar which keeps track of the maximum value seen so far on the current path. 
        At each node, we compare its value with maxSoFar; if it is greater or equal, we increment the count. 
        Then we update maxSoFar as the maximum of current node value and previous maxSoFar, and recursively 
        process the left and right subtrees. This ensures each node is evaluated correctly based on its path.
        */

        if(root->val >= maxSoFar) {
            count++;
        }

        maxSoFar = max(maxSoFar, root->val);

        func(root->left, maxSoFar, count);
        func(root->right, maxSoFar, count);
    }

    int goodNodes(TreeNode* root) {
        int count = 0;
        func(root, root->val, count);
        return count;
    }
};

// 🔹 Driver Code
int main() {
    /*
            3
           / \
          1   4
         /   / \
        3   1   5
    */

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(3);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(5);

    Solution obj;
    cout << obj.goodNodes(root);

    return 0;
}