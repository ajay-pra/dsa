// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

#include <bits/stdc++.h>
using namespace std;

/* Tree Node */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// This solution treats the Binary Search Tree like a sorted 
// structure without actually converting it into an 
// array. It uses two iterators: one performs a normal 
// inorder traversal (which gives values from smallest to largest), 
// and the other performs a reverse inorder traversal 
// (which gives values from largest to smallest). 
// These two iterators behave like the left and right 
// pointers in the classic two-pointer approach used on 
// sorted arrays. Initially, the left iterator points 
// to the smallest value and the right iterator points 
// to the largest value. At each step, their values are 
// added and compared with the target k. If the sum 
// equals k, we return true. If the sum is smaller 
// than k, we move the left iterator forward to get a 
// larger value. If the sum is greater than k, we move 
// the right iterator backward to get a smaller value. 
// The stack inside each iterator ensures that traversal 
// resumes correctly (even moving back to parent nodes), 
// so we efficiently explore the BST without extra space 
// for storing all elements.

/* BST Iterator */
class BSTIterator {
public:
    stack<TreeNode*> st;
    bool reverse;

    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }

    void pushAll(TreeNode* root) {
        while (root != nullptr) {
            st.push(root);
            if (!reverse)
                root = root->left;   // normal inorder
            else
                root = root->right;  // reverse inorder
        }
    }

    int next() {
        TreeNode* temp = st.top();
        st.pop();

        if (!reverse)
            pushAll(temp->right);   // move forward
        else
            pushAll(temp->left);    // move backward

        return temp->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};

/* Solution */
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;

        BSTIterator left(root, false);   // smallest
        BSTIterator right(root, true);   // largest

        int i = left.next();
        int j = right.next();

        while (i < j) {
            if (i + j == k) return true;
            else if (i + j < k) {
                if (left.hasNext()) i = left.next();
                else return false;
            } else {
                if (right.hasNext()) j = right.next();
                else return false;
            }
        }
        return false;
    }
};

/* Helper to insert in BST */
TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

/* Driver Code */
int main() {
    TreeNode* root = nullptr;

    // Creating BST
    vector<int> values = {5, 3, 7, 2, 4, 6, 8};
    for (int val : values) {
        root = insert(root, val);
    }

    int k = 9;

    Solution obj;
    if (obj.findTarget(root, k))
        cout << "Pair exists\n";
    else
        cout << "Pair does not exist\n";

    return 0;
}