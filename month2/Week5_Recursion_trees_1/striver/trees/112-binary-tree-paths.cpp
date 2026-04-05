// https://leetcode.com/problems/binary-tree-paths/submissions/1967534723/

#include <bits/stdc++.h>
using namespace std;

// Inside this I have used recursion to store all 
// the paths and whenever i encountered any leaf 
// node then filled that in the ans vector else 
// I am traversing left and right

// TC - O(N + number_of_paths * path_length) ≈ O(N^2) worst case
// SC - O(N)/O(H) (recursive stack) + O(H) (temp vector) + O(N^2) for storing all answer

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
    void traverse(TreeNode* root, vector<vector<int>> &ans, vector<int> &temp){
        if(root == nullptr){
            return;
        }

        temp.push_back(root->val);

        if(root->left == nullptr && root->right == nullptr){
            ans.push_back(temp);
        } else {
            traverse(root->left, ans, temp);
            traverse(root->right, ans, temp);
        }

        temp.pop_back(); // backtrack
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> temp;
        traverse(root, ans, temp);
        vector<string> ans2;
        for(int i = 0; i < ans.size(); i++){
            string s = "";
            for(int j = 0; j < ans[i].size(); j++){
                s += to_string(ans[i][j]);
                if(j != ans[i].size() - 1){
                    s += "->";
                }
            }
            ans2.push_back(s);
        }

        return ans2;
    }
};


class Solution2 {
public:
    bool traverse(TreeNode* root, int target, vector<int> &temp){
        if(root == nullptr) return false;

        temp.push_back(root->val);
        if(root->val == target){
            return true;
        }
        if(traverse(root->left, target, temp) || traverse(root->right, target, temp)){
            return true;
        }else{
            temp.pop_back();
            return false;
        }
        
    }

    vector<int> rootToNode(TreeNode* root, int target){
        vector<int> temp;
        traverse(root, target, temp);
        return temp;
    }
};

int main() {
    /*
            1
          /   \
         2     3
          \
           5

    Expected Output:
    1->2->5
    1->3
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);

    Solution obj;
    vector<string> result = obj.binaryTreePaths(root);

    for(auto &path : result){
        cout << path << endl;
    }

    return 0;
}