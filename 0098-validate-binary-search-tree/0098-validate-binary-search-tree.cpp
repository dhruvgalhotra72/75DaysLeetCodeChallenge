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
//Method - 1
void inOrderT(TreeNode *root,vector<int> &ary){
    if(root==NULL) return ;
    inOrderT(root->left , ary);
    ary.push_back(root->val);
    inOrderT(root->right , ary);
}
bool isSorted(vector<int> &ary , int n)
{
    if(n==0) return true;
    if(ary[n] <= ary[n-1]) return false;
    return isSorted(ary,n-1);
} 
bool isValidBST(TreeNode* root) {
       vector<int> ary;
       inOrderT(root,ary);
       return(isSorted(ary,ary.size()-1)); 
    }

};