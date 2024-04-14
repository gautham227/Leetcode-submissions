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
    int dfs(TreeNode* n, bool left){
        if(n==NULL)return 0;
        if(n->left==NULL && n->right==NULL){
            if(left)return n->val;
            return 0;
        }
        return dfs(n->left, true)+dfs(n->right, false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return dfs(root,false);
    }
};