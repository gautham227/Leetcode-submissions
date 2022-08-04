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
    
    void dfs(TreeNode* root, vector<TreeNode*> &v){
        v.push_back(root);
        if(root->left!=NULL)dfs(root->left, v);
        if(root->right!=NULL)dfs(root->right,v);
    }
    
    void flatten(TreeNode* root){
        if(root==NULL)return;
        vector<TreeNode*> v;
        dfs(root, v);
        for(int i=0;i<v.size()-1;i++){
            v[i]->left=NULL;
            v[i]->right=v[i+1];
        }
        return;
    }
};