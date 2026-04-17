class Solution {
public:

    // Function to check if two trees are identical
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Both null
        if (p == NULL && q == NULL)
            return true;

        // One null
        if (p == NULL || q == NULL)
            return false;

        // Value mismatch
        if (p->val != q->val)
            return false;

        // Check left and right
        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // If root is null
        if (root == NULL)
            return false;

        // If trees match
        if (isSameTree(root, subRoot))
            return true;

        // Check in left or right subtree
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};