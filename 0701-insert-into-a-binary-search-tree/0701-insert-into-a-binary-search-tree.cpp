/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // If tree is empty, create a new node
        if (root == nullptr)
            return new TreeNode(val);

        // Insert into the right subtree if val > root->val
        if (val > root->val)
            root->right = insertIntoBST(root->right, val);
        // Insert into the left subtree if val < root->val
        else
            root->left = insertIntoBST(root->left, val);

        // Return the unchanged root pointer
        return root;
    }
};
