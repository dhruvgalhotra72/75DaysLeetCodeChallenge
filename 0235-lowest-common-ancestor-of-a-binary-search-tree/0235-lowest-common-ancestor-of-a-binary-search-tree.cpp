/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        while (root != NULL) {
            
            // both nodes are smaller → go left
            if (p->val < root->val && q->val < root->val) {
                root = root->left;
            }
            // both nodes are greater → go right
            else if (p->val > root->val && q->val > root->val) {
                root = root->right;
            }
            // split point → this is LCA
            else {
                return root;
            }
        }
        
        return NULL;
    }
};