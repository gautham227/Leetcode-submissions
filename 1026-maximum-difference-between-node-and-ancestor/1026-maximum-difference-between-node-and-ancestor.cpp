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
    int dfs(TreeNode* root, int mini, int maxi){
        if(root==NULL)return maxi-mini;
        return max(dfs(root->left,min(mini,root->val), max(maxi,root->val)),dfs(root->right,min(mini,root->val), max(maxi,root->val)));
    }
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root,root->val,root->val);
    }
};