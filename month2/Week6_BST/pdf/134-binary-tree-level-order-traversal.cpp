// https://leetcode.com/problems/binary-tree-level-order-traversal/

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */

//Level order traversal works using a queue to process nodes 
// level by level, starting from the root. Initially, the root node 
// is pushed into the queue, and then we repeatedly process nodes 
// while the queue is not empty. For each level, we first determine 
// the number of nodes present (queue size), which ensures we only 
// process nodes belonging to the current level. Each node is removed 
// from the queue, its value is stored, and its left and right children 
// (if they exist) are added to the queue for the next level. 
// This process continues until all nodes are visited, resulting 
// in a traversal that moves horizontally across the tree level by 
// level rather than vertically like DFS.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> level;

            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            ans.push_back(level);
        }
        return ans;
    }
};

// 🔹 Driver Code
int main() {
    /*
            1
           / \
          2   3
         / \   \
        4   5   6
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    Solution obj;
    vector<vector<int>> result = obj.levelOrder(root);

    // Print result
    for(auto level : result){
        for(auto val : level){
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}