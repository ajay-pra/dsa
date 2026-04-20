// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

#include <bits/stdc++.h>
using namespace std;


// In this approach, we leverage the property of a Binary Search Tree 
// (BST) that its inorder traversal is always sorted. Given the preorder 
// traversal, we first create the inorder traversal by sorting the preorder 
// array. Once we have both preorder and inorder, we can reconstruct the 
// tree using the standard tree construction technique. The first element 
// of preorder is always the root. Using a hashmap, we find this root in 
// the inorder array, which helps us determine how many nodes belong to 
// the left subtree. Everything to the left of the root in inorder forms 
// the left subtree, and everything to the right forms the right subtree. 
// We recursively repeat this process for left and right parts until the 
// tree is constructed.

// Time Complexity:
// Sorting → O(n log n)
// Tree construction → O(n)
// Overall → O(n log n)
// Space Complexity:
// HashMap → O(n)
// Recursion stack → O(h) (worst case O(n))
// Overall → O(n)

class Solution {
public:
    TreeNode* constructTree(vector<int>& preorder, int preStart, int preEnd,
                            vector<int>& inorder, int inStart, int inEnd,
                            unordered_map<int, int> &inMap){
        
        // Base case: no nodes left to construct
        if(preStart > preEnd || inStart > inEnd) return NULL;

        // Step 1: Root is always first element of preorder
        TreeNode* root = new TreeNode(preorder[preStart]);

        // Step 2: Find root index in inorder using map
        int inRoot = inMap[preorder[preStart]];

        // Step 3: Number of elements in left subtree
        int numsLeft = inRoot - inStart;

        // Step 4: Recursively build left subtree
        root->left = constructTree(preorder,
                                   preStart + 1,
                                   preStart + numsLeft,
                                   inorder,
                                   inStart,
                                   inRoot - 1,
                                   inMap);

        // Step 5: Recursively build right subtree
        root->right = constructTree(preorder,
                                    preStart + numsLeft + 1,
                                    preEnd,
                                    inorder,
                                    inRoot + 1,
                                    inEnd,
                                    inMap);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.empty()) return NULL;

        // Generate inorder by sorting preorder
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());

        // Create value → index mapping
        unordered_map<int, int> inMap;
        for(int i = 0; i < inorder.size(); i++){
            inMap[inorder[i]] = i;
        }

        // Construct tree
        return constructTree(preorder, 0, preorder.size()-1,
                             inorder, 0, inorder.size()-1, inMap);
    }
};


// This is the optimal approach that avoids constructing the inorder 
// array entirely. It uses the inherent properties of a BST along with 
// preorder traversal. In preorder, we always process nodes as root → left → right. 
// We maintain a global index to track the current node in preorder. 
// Additionally, we use a "bound" value to restrict which nodes can be 
// part of the current subtree. For the left subtree, all values must be 
// less than the root, so we set the bound as root->val. For the right 
// subtree, the bound remains the same as the parent. If the current 
// value exceeds the bound, we stop recursion. This ensures that each 
// node is placed correctly in the BST. Since each element is processed 
// only once, this approach is highly efficient.

class Solution2 {
public:
    TreeNode* construct(vector<int>& preorder, int& index, int bound){
        
        // Stop if all elements are used OR value exceeds allowed bound
        if(index >= preorder.size() || preorder[index] > bound){
            return nullptr;
        }

        // Create root from current index
        TreeNode* root = new TreeNode(preorder[index++]);

        // Build left subtree (values must be < root->val)
        root->left = construct(preorder, index, root->val);

        // Build right subtree (values must be < bound)
        root->right = construct(preorder, index, bound);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;

        // Initial bound is infinity
        return construct(preorder, index, INT_MAX);
    }
};



int main() {
    vector<int> preorder = {8, 5, 1, 7, 10, 12};

    // Approach 1
    Solution1 sol1;
    TreeNode* root1 = sol1.bstFromPreorder(preorder);
    cout << "Inorder (Approach 1): ";
    printInorder(root1);
    cout << endl;

    // Approach 2 (Optimal)
    Solution2 sol2;
    TreeNode* root2 = sol2.bstFromPreorder(preorder);
    cout << "Inorder (Approach 2): ";
    printInorder(root2);
    cout << endl;

    return 0;
}