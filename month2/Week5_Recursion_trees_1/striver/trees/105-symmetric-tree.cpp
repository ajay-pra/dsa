#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = right = nullptr;
    }
};

// Inside this I have checked if root is nullptr then I have 
// called a recursive function in which I am checking the left 
// and right nodes values and pointers and acordingly returning the ans;
// TC - O(n)
// SC - O(H), H = log N (Balanced Tree), H = N (Skewed Tree)

class Solution {
public:
    bool checkSymmetry(TreeNode* left, TreeNode* right){
        if(left == nullptr && right == nullptr) return true;
        if(left == nullptr || right == nullptr) return false;
        if(left->val != right->val) return false;

        return checkSymmetry(left->left, right->right) &&
               checkSymmetry(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        return checkSymmetry(root->left, root->right);
    }
};

TreeNode* buildTree() {
    /*
            1
           / \
          2   2
         / \ / \
        3  4 4  3
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    return root;
}

int main() {
    TreeNode* root = buildTree();
    Solution obj;
    bool result = obj.isSymmetric(root);
    if(result)
        cout << "Tree is Symmetric" << endl;
    else
        cout << "Tree is NOT Symmetric" << endl;
    return 0;
}