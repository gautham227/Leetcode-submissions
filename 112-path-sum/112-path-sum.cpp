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
    bool ans=false;
    void dfs(TreeNode* root, int t, int su){
        if(root->left==NULL && root->right==NULL){
            if(su+root->val==t){
                ans=true;
            }
            return;
        }
        if(root->left!=NULL){
            dfs(root->left,t,su+root->val);
        }
        if(root->right!=NULL){
            dfs(root->right,t,su+root->val);
        }
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL)return false;
        dfs(root,targetSum,0);
        return ans;
    }
};