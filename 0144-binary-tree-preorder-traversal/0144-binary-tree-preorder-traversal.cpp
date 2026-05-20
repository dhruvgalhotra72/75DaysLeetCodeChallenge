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
//https://leetcode.com/problems/binary-tree-preorder-traversal/description/?envType=problem-list-v2&envId=tree
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
   
    
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> vec;
        if(root==NULL)
            return vec;

        
        preorder(root,vec);
        return vec;
        
    }
    //With Loop:
    void preorder(TreeNode *root,vector<int> &vec)
    {
        stack<TreeNode *> stk;
        stk.push(root);

        while(!stk.empty())
            {
                TreeNode *nod=stk.top(); stk.pop();

                vec.push_back(nod->val);
                if(nod->right!=NULL)
                    stk.push(nod->right);
                if(nod->left!=NULL)
                    stk.push(nod->left);
             }  
    }
    //Without Loop
    /*void preorder(TreeNode *root,vector<int> &vec)
        {
            if(root==NULL)
                return;
           
            vec.push_back(root->val);
            preorder(root->left,vec);
            preorder(root->right,vec);  
        }
        */
};