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
    int dfs(TreeNode* n){
        if(n->left==NULL && n->right==NULL){
            return n->val;
        }
        if(n->val==2){
            return dfs(n->left)|dfs(n->right);
        }
        return dfs(n->left)&dfs(n->right);
    }
public:
    bool evaluateTree(TreeNode* root) {
        return dfs(root);
    }
};