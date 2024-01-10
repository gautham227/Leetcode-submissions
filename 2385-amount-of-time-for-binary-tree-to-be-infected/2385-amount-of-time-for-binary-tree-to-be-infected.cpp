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
    vector<vector<int> >adj;
    void dfs(TreeNode* root){
        if(root==NULL)return;
        if(root->left!=NULL){
            adj[root->val].push_back((root->left)->val);
            adj[(root->left)->val].push_back(root->val);
            dfs(root->left);
        }
        if(root->right!=NULL){
            adj[root->val].push_back((root->right)->val);
            adj[(root->right)->val].push_back(root->val);
            dfs(root->right);
        }
    }
    
    void depth(int val, int par, int dep){
        ans=max(ans,dep);
        for(auto ch: adj[val]){
            if(ch==par)continue;
            depth(ch, val, dep+1);
        }
        
    }
    
    int amountOfTime(TreeNode* root, int start) {
        adj.resize(100000+5);
        dfs(root);
        depth(start,-1,0);
        return ans;
    }
};