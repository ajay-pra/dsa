// https://takeuforward.org/plus/dsa/problems/inorder-successor-and-predecessor-in-bst?subject=dsa&approach=brute

#include <bits/stdc++.h>
using namespace std;


// We leverage the Binary Search Tree property to efficiently find the inorder predecessor and successor in a single traversal. While traversing the tree, if the current node’s value is greater than the key, it is a potential successor, so we move left to find a smaller valid candidate. If the value is less than the key, it is a potential predecessor, so we move right to find a larger candidate. When the key node is found, we further explore its left subtree to get the maximum value (predecessor) and its right subtree to get the minimum value (successor). This ensures we correctly identify the closest smaller and larger elements relative to the key in optimal time.

// Definition of TreeNode
struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    vector<int> succPredBST(TreeNode* root, int key) {
        int succ = -1, pred = -1;
        TreeNode* curr = root;

        while (curr) {
            if (curr->data == key) {
                
                // find predecessor (max in left subtree)
                TreeNode* temp = curr->left;
                while (temp) {
                    pred = temp->data;
                    temp = temp->right;
                }

                // find successor (min in right subtree)
                temp = curr->right;
                while (temp) {
                    succ = temp->data;
                    temp = temp->left;
                }
                break;
            }
            else if (key < curr->data) {
                succ = curr->data;
                curr = curr->left;
            }
            else {
                pred = curr->data;
                curr = curr->right;
            }
        }

        return {succ, pred};
    }
};



// Insert into BST
TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}



int main() {
    /*
        Creating BST:
                5
             /     \
            2       10
          /  \     /   \
         1    4   7     12
                         /  \
                       11    16
                      /   \
                     9     15
    */

    vector<int> values = {5,2,10,1,4,7,12,11,16,9,15};
    TreeNode* root = NULL;

    for (int val : values) {
        root = insert(root, val);
    }

    int key = 10;

    Solution obj;
    vector<int> ans = obj.succPredBST(root, key);

    cout << "Successor: " << ans[0] << endl;
    cout << "Predecessor: " << ans[1] << endl;

    return 0;
}