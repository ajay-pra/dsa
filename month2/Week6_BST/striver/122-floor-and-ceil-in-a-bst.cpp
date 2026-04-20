// https://takeuforward.org/plus/dsa/problems/floor-and-ceil-in-a-bst


#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
class TreeNode {
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
public:
    vector<int> floorCeilOfBST(TreeNode* root, int key) {
        int floor = -1, ceil = -1;
        TreeNode* current = root; 
        
        // Find Floor
        while (current) {
            if (current->data == key) {
                floor = current->data;
                break;
            }
            if (current->data > key) {
                current = current->left;
            } else {
                floor = current->data;
                current = current->right;
            }
        }

        current = root;

        // Find Ceil
        while (current) {
            if (current->data == key) {
                ceil = current->data;
                break;
            }
            if (current->data < key) {
                current = current->right;
            } else {
                ceil = current->data;
                current = current->left;
            }
        }

        return {floor, ceil};
    }
};

// Helper to insert into BST
TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    
    return root;
}

int main() {
    TreeNode* root = nullptr;

    // Hardcoded BST values
    vector<int> values = {8, 4, 12, 2, 6, 10, 14};
    for (int val : values) {
        root = insert(root, val);
    }

    // Hardcoded key
    int key = 5;

    Solution obj;
    vector<int> res = obj.floorCeilOfBST(root, key);

    cout << "Key: " << key << endl;
    cout << "Floor: " << res[0] << endl;
    cout << "Ceil: " << res[1] << endl;

    return 0;
}