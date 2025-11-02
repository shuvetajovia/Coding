class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Both null -> same
        if (!p && !q) return true;
        // One null, one not -> different
        if (!p || !q) return false;
        // Values differ -> different
        if (p->val != q->val) return false;
        // Recursively check left and right subtrees
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};