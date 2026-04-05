// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) { val = x; left = right = nullptr; }
};

// TC - O(n) + O(n) (reversing)
// SC - O(n)

class Solution1 {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        queue<TreeNode*> q;
        TreeNode* node = root;
        q.push(node);
        int count = 1;
        while(!q.empty()){
            int size = q.size();
            vector<int> lavel;
            for(int i=0;i<size;i++){
                TreeNode* front = q.front();
                lavel.push_back(front->val);
                q.pop();
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            if(count%2 == 0){
                reverse(lavel.begin(), lavel.end());
                ans.push_back(lavel);
            }else{
                 ans.push_back(lavel);
            }
            count++;
        }
        return ans;
    }
};

// TC - O(n)
// SC - O(n)

class Solution2 {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;

        queue<TreeNode*> q;
        q.push(root);

        bool leftToRight = true;

        while(!q.empty()){
            int size = q.size();
            vector<int> level(size);

            for(int i = 0; i < size; i++){
                TreeNode* front = q.front();
                q.pop();

                int index = leftToRight ? i : (size - i - 1);
                level[index] = front->val;

                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }

            leftToRight = !leftToRight;
            ans.push_back(level);
        }

        return ans;
    }
};



void printZigzag(vector<vector<int>>& ans) {
    for(auto &level : ans){
        for(int val : level){
            cout << val << " ";
        }
        cout << endl;
    }
}

// Example tree builder
TreeNode* buildTree() {
    /*
            1
           / \
          2   3
         / \   \
        4   5   6
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    return root;
}

int main() {
    TreeNode* root = buildTree();

    cout << "=== Solution1 (with reverse) ===" << endl;
    Solution1 sol1;
    vector<vector<int>> ans1 = sol1.zigzagLevelOrder(root);
    printZigzag(ans1);

    cout << "=== Solution2 (optimized index-based) ===" << endl;
    Solution2 sol2;
    vector<vector<int>> ans2 = sol2.zigzagLevelOrder(root);
    printZigzag(ans2);

    return 0;
}