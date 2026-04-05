// https://takeuforward.org/plus/dsa/problems/top-view-of-bt?subject=dsa&approach=brute&tab=submissions

#include <bits/stdc++.h>
using namespace std;

// inside this I have used the same concept as the vertical oredr traversal

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
     TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
};

class Solution{
    public:
    vector<int> topView(TreeNode *root){
        //your code goes here
        queue<pair<TreeNode* , int>> q;
        map<int,int> mp;
        q.push({root, 0});
        while(!q.empty()){
            auto p = q.front();
            int x = p.second;
            TreeNode* node = p.first;
            q.pop();
            if(mp.find(x) == mp.end()){
                mp[x] = node -> data;
            }
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