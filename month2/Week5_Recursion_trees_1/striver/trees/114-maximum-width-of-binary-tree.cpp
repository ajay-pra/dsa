// https://leetcode.com/problems/maximum-width-of-binary-tree/
#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
// We solve the problem using level order traversal (BFS) 
// while assigning each node an index as if the tree 
// were a complete binary tree. The root starts at 
// index 0, and for any node at index i, its left and 
// right children are assigned indices 2i + 1 and 2i + 2. 
// At each level, we track the indices of the first 
// and last nodes to calculate the width as (last − first + 1). 
// To avoid integer overflow, indices are normalized 
// at every level by subtracting the minimum index. 
// The maximum width across all levels is returned as 
// the final answer.

//  TC - O(n)
//  SC - O(n)

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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        long long width = 0;

        while(!q.empty()){
            long long mini = q.front().second;
            int size = q.size();
            long long left = 0, right = 0;

            for(int i = 0; i < size; i++){
                TreeNode* node = q.front().first;
                long long cur_id = q.front().second - mini;
                q.pop();

                if(i == 0) left = cur_id;
                if(i == size - 1) right = cur_id;

                if(node->left){
                    q.push({node->left, cur_id * 2 + 1});
                }
                if(node->right){
                    q.push({node->right, cur_id * 2 + 2});
                }
            }

            width = max(width, right - left + 1);
        }

        return (int)width;
    }
};


// 🔥 Helper function to build a sample tree
TreeNode* buildTree() {
    /*
            1
          /   \
         2     3
        /       \
       4         7
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->right = new TreeNode(7);
    return root;
}


// 🚀 Driver Code
int main() {
    TreeNode* root = buildTree();
    Solution obj;
    int result = obj.widthOfBinaryTree(root);
    cout << "Maximum Width of Binary Tree: " << result << endl;
    return 0;
}