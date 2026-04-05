// https://takeuforward.org/plus/dsa/problems/bottom-view-of-bt?

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {
  public:
    vector <int> bottomView(TreeNode *root){
    	//your code goes here
           //your code goes here
        queue<pair<TreeNode* , int>> q;
        map<int,int> mp;
        q.push({root, 0});
        while(!q.empty()){
            auto p = q.front();
            int x = p.second;
            TreeNode* node = p.first;
            q.pop();
            mp[x] = node -> data;
            if(node-> left) q.push({node->left, x-1});
            if(node-> right) q.push({node->right, x+1});
        }
        vector<int> ans;
        for (auto it : mp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};