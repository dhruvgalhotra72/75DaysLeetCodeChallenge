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
    TreeNode* deleteNode(TreeNode* root, int wanted) {
        if(root==NULL) return NULL;
        if(wanted < root->val)
            root->left = deleteNode(root->left , wanted);
            else
            if(wanted > root->val)
                root->right = deleteNode(root->right , wanted);
                else
                {
                    if(root->left==NULL && root->right==NULL) return NULL;
                    else if(root->left!=NULL && root->right==NULL) return root->left;
                    else if(root->left==NULL && root->right!=NULL) return root->right;
                    else
                    {
                        TreeNode* ptr = root->right;
                        while(ptr->left != NULL)
                        {
                            ptr = ptr->left;
                        }
                        root->val = ptr->val;
                        root->right = deleteNode(root->right , ptr->val);
                    }
                }
                return root;
    }
};