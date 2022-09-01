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
    void dfs(TreeNode* node, int v){
        if(node->val>=v)ans++;
        if(node->left!=NULL)dfs(node->left, max(v, node->val));
        if(node->right!=NULL)dfs(node->right, max(v, node->val));
        return;
    }
    int goodNodes(TreeNode* root) {
        dfs(root, (int)-1e9);
        return ans;
    }
};