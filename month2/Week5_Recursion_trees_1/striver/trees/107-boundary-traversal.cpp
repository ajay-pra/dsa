// https://takeuforward.org/plus/dsa/problems/boundary-traversal?subject=dsa&approach=brute&sidebar=open&tab=submissions

#include <bits/stdc++.h>
using namespace std;

// Inside this We have to do root -> left -> leaf -> right 
// traversal, also one thing to keep in mind that while doing 
// left traversal if i will put root then it wont work

// TC - O(H) + O(N) + O(H) = O(N)
// SC - O(H) (excluding output)

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
     TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
};

class Solution{
public:
    bool LeafNode(TreeNode* node){
        if(node -> left == nullptr && node -> right == nullptr) return true;
        else return false;
    }
    void left(TreeNode* root, vector <int> &ans){
        root = root->left;
        while(root){
            if(!LeafNode(root)) ans.push_back(root->data);
            if(root->left) root = root->left;
            else root = root->right;
        }
    }
    void right(TreeNode* root, vector <int> &ans){
        root = root->right;
        vector<int> temp;
        while(root){
            if(!LeafNode(root)) temp.push_back(root->data);
            if(root->right) root = root->right;
            else root = root->left;
        }
        for (int i = temp.size() - 1; i >= 0; --i) {
            ans.push_back(temp[i]);
        }
    }
    void leaf(TreeNode* root, vector <int> &ans){
        if(root == nullptr){
            return;
        }
        if(LeafNode(root)){
            ans.push_back(root->data);
        }
        leaf(root->left, ans);
        leaf(root->right, ans);
    }
    vector <int> boundary(TreeNode* root){
    	//your code goes here
        vector<int> ans;
        if (!root) {
            return ans;
        }
        if (!LeafNode(root)) {
            ans.push_back(root->data);
        }
        left(root, ans);
        leaf(root, ans);
        right(root, ans);
        return ans;
    }
};



// 🔹 Driver Code
int main() {

    /*
            1
          /   \
         2     3
        / \   / \
       4   5 6   7
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution obj;
    vector<int> result = obj.boundary(root);

    cout << "Boundary Traversal: ";
    for(int x : result){
        cout << x << " ";
    }

    return 0;
}