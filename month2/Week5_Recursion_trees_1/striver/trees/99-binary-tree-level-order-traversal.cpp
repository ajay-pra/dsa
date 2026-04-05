// https://leetcode.com/problems/binary-tree-level-order-traversal/

#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Inside this I have used queue, first of all I have put the root 
// of the tree to queue and run a loop while(q.size()) and inside that
// I have run a loop from 0 to size of the queue and get the front of 
// the ques put its value to the lavel and then pop it. If front-> left 
// is there then pust that in queue and if front-> right is there then 
// push tat too in queue

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            int size = q.size();
            vector<int> level;
            for(int i=0;i<size;i++){
                TreeNode* front = q.front();
                level.push_back(front->val);
                q.pop();
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            ans.push_back(level);            
        }
        return ans;
    }
};


int main() {
    /*
        Constructing this tree:
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
    for(auto level : result) {
        for(auto val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}