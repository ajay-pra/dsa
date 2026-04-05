
// https://leetcode.com/problems/binary-tree-preorder-traversal/

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


// recursive way
// TC - O(n)
// SC - O(h)
class Solution {
public:
    void traverse(TreeNode* root, vector<int> &ans){
        if(root == nullptr){
            return;
        }
        ans.push_back(root->val);
        traverse(root->left, ans);
        traverse(root->right, ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        traverse(root, ans);
        return ans;
    }
};


// Iterative way

// inside this I have used an stack to do the iteration, 
// basically i have pushed the root first into the stack 
// and after that run a while loop in which i am checking 
// the current node if it is not null then i am  pushing its value to the ans 
// putting that node into the stack, else if st.size == 0 then I am breaking 
// out of the while loop and then I am chcing the top of the 
// stack and poping the stack, 
// if top->right is there then I am pointing my node to the top->right. 
// at the end I am returning the ans
// TC - O(n)
// SC - O(h)
class Solution2 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode *> st;
        TreeNode* node = root;
        vector<int> preorder;
        while(true){
            if(node != nullptr){
                preorder.push_back(node->val);
                st.push(node);
                node = node->left;
            }else{
                if(st.empty()) break;
                node = st.top();
                node = node->right;
                st.pop();
            }
        }
        return preorder;
    }
};


int main() {
    /*
        Example Tree:
              1
               \
                2
               /
              3
    */

    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution obj;
    vector<int> result = obj.preorderTraversal(root);

    cout << "Inorder Traversal: ";
    for(int x : result){
        cout << x << " ";
    }

    return 0;
}