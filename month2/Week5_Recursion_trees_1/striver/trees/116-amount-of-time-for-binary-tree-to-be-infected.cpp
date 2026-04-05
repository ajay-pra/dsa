// https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/submissions/1968366577/


#include <bits/stdc++.h>
using namespace std;

// We treat the tree like a graph. First, we create a parent map 
// so we can move upward as well. Then we start BFS 
// from the start node, spreading infection to left, 
// right, and parent nodes. Each BFS level represents 
// 1 unit time, and we count how many levels are 
// needed until all nodes are infected.

// TC - O(n)
// SC - O(n)

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Create parent mapping + find start node
void parentNodeMap(TreeNode* root,
                   unordered_map<TreeNode*, TreeNode*>& parentMap,
                   TreeNode*& startNode,
                   int start) {

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node->val == start) startNode = node;

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

class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {

        unordered_map<TreeNode*, TreeNode*> parentMap;
        TreeNode* startNode = nullptr;

        parentNodeMap(root, parentMap, startNode, start);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;

        q.push(startNode);
        visited[startNode] = true;

        int time = 0;

        while (!q.empty()) {
            int size = q.size();
            bool spread = false;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left && !visited[node->left]) {
                    visited[node->left] = true;
                    q.push(node->left);
                    spread = true;
                }

                if (node->right && !visited[node->right]) {
                    visited[node->right] = true;
                    q.push(node->right);
                    spread = true;
                }

                if (parentMap.count(node) && !visited[parentMap[node]]) {
                    visited[parentMap[node]] = true;
                    q.push(parentMap[node]);
                    spread = true;
                }
            }

            if (spread) time++;
        }

        return time;
    }
};

// Driver Code
int main() {
    /*
            1
           / \
          2   3
         /   / \
        4   5   6
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);

    Solution obj;
    int start = 5;

    cout << "Time to burn tree: " << obj.amountOfTime(root, start);

    return 0;
}