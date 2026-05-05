// https://leetcode.com/problems/binary-tree-maximum-path-sum

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

// inside this also the idea is simple we will calculate the left sum, 
// right sum and while backtracking will have to return max(ls,rs)+root->val; 
// also the  ans is calculated just before the backtracking 
// ans = max(ans, ls+rs+root->val); just one thing needs to 
// be remember is that while calculating ls or rs will 
// have to take max(0, maxSum(root->left, ans)); 
// in order to avoid negative sums

// TC - O(n)
// SC - O(H), H = log N (Balanced Tree), H = N (Skewed Tree)

class Solution {
public:
    int maxSum(TreeNode* &root, int &ans){
        if(root == nullptr) {
            return 0;
        }
        int ls = max(0, maxSum(root->left, ans));
        int rs = max(0, maxSum(root->right, ans));
        ans = max(ans, ls+rs+root->val);
        return max(ls,rs)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        maxSum(root, ans);
        return ans;
    }
};

TreeNode* buildTree() {
    /*
            -10
            /  \
           9   20
              /  \
             15   7
    */

    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    return root;
}

int main() {
    TreeNode* root = buildTree();

    Solution obj;
    int result = obj.maxPathSum(root);

    cout << "Maximum Path Sum: " << result << endl;

    return 0;
}