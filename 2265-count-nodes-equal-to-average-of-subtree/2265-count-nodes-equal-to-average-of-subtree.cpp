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
    pair<int,int> dfs(TreeNode* root){
        if(root->left==NULL && root->right==NULL){ans++;return{root->val,1};}
        pair<int,int> l={0,0}, r={0,0};
        if(root->left!=NULL)l=dfs(root->left);
        if(root->right!=NULL)r=dfs(root->right);
        int su=(l.first+r.first+root->val)/(l.second+r.second+1);
        if(su==root->val)ans++;
        return {l.first+r.first+root->val, l.second+r.second+1};
    }
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};