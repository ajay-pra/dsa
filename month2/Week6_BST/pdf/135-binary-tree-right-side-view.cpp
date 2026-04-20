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
    vector<int> rightSideView(TreeNode* root) {

        /*
        The right side view of a binary tree represents the set of nodes visible when the tree is viewed from the right side. 
        This solution uses level order traversal (BFS) with a queue to process the tree level by level. For each level, we iterate 
        through all nodes currently in the queue, and the last node processed at that level (i == size - 1) is the one visible 
        from the right side, so we store its value. While traversing, we push left and right children into the queue so that the 
        next level can be processed. This ensures that for every level, only the rightmost node is added to the result.
        */

        vector<int> ans;
        if(!root) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();

            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();

                if(i == size - 1) {
                    ans.push_back(node->val);
                }

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
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
           \    \
            5    4
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    Solution obj;
    vector<int> result = obj.rightSideView(root);

    // Print result
    for(int val : result){
        cout << val << " ";
    }

    return 0;
}