#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = right = nullptr;
    }
};
// Deletion in a BST is performed recursively by first 
// locating the node to delete using BST properties. 
// Once found, three cases are handled: if the node 
// has no children, it is simply removed by returning 
// nullptr; if it has one child, the child is returned 
// so that the parent connects directly to it; and if 
// it has two children, the node’s value is replaced 
// with its inorder successor (minimum value from the 
// right subtree), and then that successor node is
// deleted recursively from the right subtree. Each 
// recursive call returns the updated subtree root, 
// ensuring proper reconnection of nodes. The time 
// complexity is O(H), where H is the height of the 
// tree, and space complexity is O(H) due to recursion.
// Insert into BST (helper for driver)
TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Inorder Traversal (to check result)
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Find minimum in subtree
TreeNode* findMin(TreeNode* root) {
    while (root->left) {
        root = root->left;
    }
    return root;
}

// Delete node in BST
TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return nullptr;

    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    }
    else {
        // Case 1: No child
        if (!root->left && !root->right) return nullptr;

        // Case 2: One child
        if (!root->left) return root->right;
        if (!root->right) return root->left;

        // Case 3: Two children
        TreeNode* minNode = findMin(root->right);
        root->val = minNode->val;
        root->right = deleteNode(root->right, minNode->val);
    }

    return root;
}

int main() {
    TreeNode* root = nullptr;

    // Hardcoded input
    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    for (int x : arr) {
        root = insert(root, x);
    }

    cout << "Inorder before deletion: ";
    inorder(root);
    cout << endl;

    int key = 50; // delete this node
    root = deleteNode(root, key);

    cout << "Inorder after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}