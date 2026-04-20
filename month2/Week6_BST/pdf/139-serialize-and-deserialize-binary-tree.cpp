// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // 🔹 Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        /*
        We perform BFS (level-order traversal) using a queue. For each node, we add its value to the
        string, and use '#' to represent null nodes. Left and right children are pushed to the queue
        even if they are null to maintain the correct tree structure. Nodes are separated by commas.
        */
        if(!root) return "";
        string str ="";
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node == nullptr) str += "#,";
            else{
                str += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            }
        }
        return str;
    }

    // 🔹 Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        /*
        To rebuild the tree from the serialized string, we split the string by commas and process nodes
        level by level using a queue. For each node, the next two entries correspond to its left and
        right children. If an entry is '#', we assign nullptr; otherwise, we create a new TreeNode and
        push it into the queue. This ensures the original structure is fully restored.
        */
        if(data.empty()) return nullptr; 

        stringstream s(data);
        string str;

        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            // Left child
            if(getline(s, str, ',')){
                if(str != "#"){
                    TreeNode* leftNode = new TreeNode(stoi(str));
                    node->left = leftNode;
                    q.push(leftNode);
                }
            }

            // Right child
            if(getline(s, str, ',')){
                if(str != "#"){
                    TreeNode* rightNode = new TreeNode(stoi(str));
                    node->right = rightNode;
                    q.push(rightNode);
                }
            }
        }

        return root;
    }
};

// 🔹 Driver Code
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
    string treeStr = ser.serialize(root);
    cout << "Serialized: " << treeStr << endl;

    TreeNode* ans = deser.deserialize(treeStr);
    cout << "Root after Deserialization: " << ans->val << endl;

    return 0;
}