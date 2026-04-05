// https://leetcode.com/problems/binary-tree-right-side-view

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        queue<pair<TreeNode*, int>> q;
        map<int, int> mp;
        q.push({root, 0});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int level = p.second;
            TreeNode* node = p.first;
            mp[level] = node -> val;
            if(node -> left) q.push({node -> left, level+1});
            if(node -> right) q.push({node -> right, level+1});
        }
        vector<int> ans;
        for(auto it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};