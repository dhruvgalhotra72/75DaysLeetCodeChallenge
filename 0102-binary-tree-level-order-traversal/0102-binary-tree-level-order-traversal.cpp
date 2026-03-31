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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vect;

        if(root==NULL) return vect;

        queue<TreeNode*> Q;
        Q.push(root);

        while(!Q.empty()){
            int size = Q.size();
            vector<int> level;

            for(int i=0;i<size;i++){
                TreeNode* ptr = Q.front();
                Q.pop();

                level.push_back(ptr->val);
                
                if(ptr->left != NULL) Q.push(ptr->left);
                if(ptr->right != NULL) Q.push(ptr->right);
            }
            vect.push_back(level);
        }
        return vect;
    }
};