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
    int f=1;
    int dfs(TreeNode* node){
        int l=0, r=0;
        if(node->left!=NULL){
            l=dfs(node->left);
        }
        if(node->right!=NULL){
            r=dfs(node->right);
        }
        if(abs(l-r)>1)f=0;
        return max(l,r)+1;
    }
    
    bool isBalanced(TreeNode* root) {
        if(root==NULL)return true;
        dfs(root);
        return f;
    }
};