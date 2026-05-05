// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */

// The problem is solved using BFS (level order traversal). 
// First, we convert the tree into an undirected graph
// by storing each node’s parent using a map. Then 
// we start BFS from the target node, exploring 
// its left child, right child, and parent. We use
// a visited set to avoid revisiting nodes. Each 
// level of BFS represents distance from the target,
// so after reaching level k, all nodes in the 
// queue are exactly k distance away, and we return
// them.

// Building parent map → O(N)
// BFS traversal → O(N)

// 👉 Total TC = O(N)

// Parent map → O(N)
// Visited set → O(N)
// Queue → O(N) (worst case)

// 👉 Total SC = O(N)
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parentMap){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if (node->left) {
                parentMap[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                parentMap[node->right] = node;
                q.push(node->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentMap;
        markParent(root, parentMap);

        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;

        q.push(target);
        visited.insert(target);

        int distance = 0;

        while(!q.empty()){
            int size = q.size();

            if(distance == k) break;

            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->left && !visited.count(node->left)){
                    q.push(node->left);
                    visited.insert(node->left);
                }

                if(node->right && !visited.count(node->right)){
                    q.push(node->right);
                    visited.insert(node->right);
                }

                if(parentMap.find(node) != parentMap.end() && 
                   !visited.count(parentMap[node])){
                    q.push(parentMap[node]);
                    visited.insert(parentMap[node]);
                }
            }

            distance++;
        }

        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front()->val);
            q.pop();
        }

        return result;
    }
};


// 🔹 Driver Code
int main() {
    /*
            3
           / \
          5   1
         / \ / \
        6  2 0  8
          / \
         7   4
    */

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution obj;
    int k = 2;

    vector<int> ans = obj.distanceK(root, root->left, k); // target = 5

    cout << "Nodes at distance " << k << ": ";
    for(int x : ans) cout << x << " ";

    return 0;
}