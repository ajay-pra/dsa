// https://leetcode.com/problems/balanced-binary-tree/

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

// brutefrce
// Inside this I I don is in bruteforce way, 
// just calculating the height of each node, 
// and if in any case i got height difference of 
// left and right greater then 1, then return -1, 
// same checked recursively for both left and right
// TC - O(n²)
// SC - O(h)

class Solution {
public:
    int height(TreeNode* root){
        if(root == nullptr) return 0;
        return 1+max(height(root->left) , height(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        if(abs(leftHeight-rightHeight)>1) return false;
        return (isBalanced(root->left) && isBalanced(root->right));
    }
};




// optimized
// Inside this I have tricked with my calculate height 
// function in which If in any case the difference bw 
// left height and right height if greater then one then return -1
// als additionl check after calculating the left or right height

// TC - O(n)
// SC - O(h)

class Solution2 {
public:
    int height(TreeNode* root) {
        if (root == NULL) return 0;

        int left = height(root->left);
        if (left == -1) return -1;

        int right = height(root->right);
        if (right == -1) return -1;

        if (abs(left - right) > 1) return -1;

        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};

int main() {
    /*
            1
           / \
          2   3
         /
        4
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    Solution obj;

    if(obj.isBalanced(root))
        cout << "Tree is Balanced\n";
    else
        cout << "Tree is NOT Balanced\n";

    return 0;
}