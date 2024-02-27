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
    int ans=0;
    
    int dfs(TreeNode* node){
        int l=0, r=0;
        if(node->left!=NULL){
            l=dfs(node->left);
        }
        if(node->right!=NULL){
            r=dfs(node->right);
        }
        ans=max(ans,l+r+1);
        return max(l,r)+1;
    }
    
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)return 0;
        dfs(root);
        return ans-1;
    }
};