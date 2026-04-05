// https://leetcode.com/problems/diameter-of-binary-tree/description/

#include <bits/stdc++.h>
using namespace std;
// inside this I have used the same height calculating logic 
// in that the diameter will be diameter = max(diameter, lh+rh);

// TC - O(n)
// SC - O(H)

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
    int height(TreeNode* &root, int &diameter){
        if(root == nullptr){
            return 0;
        }
        int lh = height(root->left, diameter);
        int rh = height(root->right, diameter);
        diameter = max(diameter, lh+rh);
        return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
};


TreeNode* buildTree() {
    /*
            1
           / \
          2   3
         / \
        4   5
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    return root;
}

int main() {
    TreeNode* root = buildTree();

    Solution obj;
    int result = obj.diameterOfBinaryTree(root);

    cout << "Diameter of Binary Tree (in edges): " << result << endl;

    return 0;
}