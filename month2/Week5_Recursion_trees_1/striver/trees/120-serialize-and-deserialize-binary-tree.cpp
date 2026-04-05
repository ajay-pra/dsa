// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

#include <bits/stdc++.h>
using namespace std;

// This approach uses BFS (level order traversal) to convert a binary 
// tree into a string and back. During serialization, we store node 
// values and use # for NULLs so the structure is preserved. During 
// deserialization, we read values sequentially and rebuild the tree 
// using a queue, assigning left and right children accordingly.

// TC - O(n)
// SC - O(n)

/* Definition for binary tree */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Serialize using BFS
    string serialize(TreeNode* root) {
        if (!root) return "#,";

        string s;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node == NULL) {
                s += "#,";
            } else {
                s += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            }
        }
        return s;
    }

    // Deserialize using BFS
    TreeNode* deserialize(string data) {
        if (data == "#,") return NULL;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode * node = q.front();
            q.pop();
            getline(s, str, ',');
            if (str != "#") {
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }
            getline(s, str, ',');
            if (str != "#") {
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }

// Helper function to print tree (Level Order)
void printTree(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node) {
            cout << node->val << " ";
            q.push(node->left);
            q.push(node->right);
        } else {
            cout << "N ";
        }
    }
    cout << endl;
}

// Driver Code
int main() {
    /*
            1
           / \
          2   3
             / \
            4   5
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Codec ser, deser;

    // Serialize
    string data = ser.serialize(root);
    cout << "Serialized: " << data << endl;

    // Deserialize
    TreeNode* newRoot = deser.deserialize(data);

    // Print to verify
    cout << "Deserialized Tree (Level Order): ";
    printTree(newRoot);

    return 0;
}