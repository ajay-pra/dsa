// https://leetcode.com/problems/binary-tree-postorder-traversal/


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


class Solution {
public:
    void func(TreeNode* root, vector<int> &ans){
        if(root == nullptr){
            return;
        }
        func(root->left, ans);
        func(root->right, ans);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root){
        vector<int> ans;
        func(root, ans);
        return ans;
    }
};

// Iterative
// Inside this I have used two stack, st1 and st2. 
// In st1 initially I have stored root and run a while loop 
// till while(!st1.empty()). inside the while loop I am checking 
// the top of the stack1 and putting the top of stack 1 to stack 2 and 
// if top-> left is there thn puting it into the st1 and similarly if 
// top-> right is there then also putting it too.

// TC -> O(n)
// SC -> O(n)

class Solution2 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;
        TreeNode* node = root;
        st1.push(node);
        while(!st1.empty()){
            TreeNode* top = st1.top();
            st1.pop();
            st2.push(top);
            if(top-> left) st1.push(top-> left);
            if(top-> right) st1.push(top-> right);
        }
        vector<int> post;
        while(!st2.empty()){
            int val = st2.top()->val;
            post.push_back(val);
            st2.pop();
        }
        return post;
    }
};



int main() {
    /* Example Tree:
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
    vector<int> result = obj.postorderTraversal(root);

    cout << "Inorder Traversal: ";
    for(int x : result){
        cout << x << " ";
    }

    return 0;
}
