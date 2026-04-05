// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

#include <bits/stdc++.h>
using namespace std;

// Inside this I have done basically lavel order traversal 
// but with slightly adjustment instead of just storing
// lavel in stack we will store vertical positions also queue will be like this queue<pair<TreeNode*, pair<int,int>>> q;
// and node maps will be like this map<int, map<int, multiset<int>>> nodesMap; we will do the travrsal and store the and at the end

// TC - O(N) (BFS traversal of all nodes) + 
// O(N log N) (map insertions for x and y) + 
// O(N log N) (multiset insertions) + O(N) 
// (building the answer)

// SC - O(N) (map + multiset storing all nodes) + 
// O(N) (queue for BFS) + O(N) (answer vector)
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*, pair<int,int>>> q;
        map<int, map<int, multiset<int>>> nodesMap;
        q.push({root, {0,0}});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int x = p.second.first;
            int y = p.second.second;
            nodesMap[x][y].insert(node->val);
            if(node->left) q.push({node->left, {x-1,y+1}});
            if(node->right) q.push({node->right, {x+1,y+1}});
        }
        vector<vector<int>> ans;
        for (auto col:nodesMap){
            vector<int> temp;
            for(auto row:col.second){
                for(auto val:row.second){
                    temp.push_back(val);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};



// 🔹 Driver Code
int main() {
    /*
            1
          /   \
         2     3
        / \   / \
       4   5 6   7
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution obj;
    vector<vector<int>> result = obj.verticalTraversal(root);

    cout << "Boundary Traversal: ";
    for (auto &col : result) {
    for (int val : col) {
        cout << val << " ";
    }
    cout << endl;
}

    return 0;
}