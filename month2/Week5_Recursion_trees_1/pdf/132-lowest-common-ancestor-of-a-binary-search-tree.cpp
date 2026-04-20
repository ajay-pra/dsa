// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/


/**
 * 🔹 Approach (LCA in BST)
 * 
 * In a Binary Search Tree (BST), left subtree contains smaller values 
 * and right subtree contains greater values than the root.
 * 
 * We use this property to find LCA efficiently:
 * - If both p and q are smaller than root → move left
 * - If both p and q are greater than root → move right
 * - Otherwise → current node is the split point → LCA
 * 
 * The split point means one node lies on left and the other on right,
 * or one of them is equal to root. Hence, we return root.
 * 
 * ⏱️ Time Complexity: O(H)
 *    - H = height of tree
 *    - Balanced BST → O(log N)
 *    - Skewed BST → O(N)
 * 
 * 💾 Space Complexity: O(H) (recursive stack)
 *    - Iterative version can make it O(1)
 */

 #include <iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        // Base case
        if (root == nullptr) return nullptr;

        // Split condition: one node on left, one on right
        if (p->val < root->val && q->val > root->val) return root;
        if (q->val < root->val && p->val > root->val) return root;

        // Both nodes lie in left subtree
        if (p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }

        // Both nodes lie in right subtree
        if (p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        }

        // If one of the nodes is equal to root
        return root;
    }
};



int main() {
    /*
            6
           / \
          2   8
         / \ / \
        0  4 7  9
          / \
         3   5
    */

    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);

    Solution obj;

    TreeNode* p = root->left;        // 2
    TreeNode* q = root->right;       // 8

    TreeNode* ans = obj.lowestCommonAncestor(root, p, q);

    cout << "LCA: " << ans->val << endl;

    return 0;
}