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
    vector<int> mp;
    int dfs(TreeNode* node){
        mp[node->val]++;
        if(node->left==NULL && node->right==NULL){
            int cntr=0;
            for(int i=1;i<=9;i++){
                cntr+=(mp[i]&1);
            }
            mp[node->val]--;
            if(cntr<2)return 1;
            return 0;
        }
        int ans=0;
        if(node->left!=NULL)ans+=dfs(node->left);
        if(node->right!=NULL)ans+=dfs(node->right);
        mp[node->val]--;
        return ans;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        mp.resize(11,0);
        return dfs(root);
    }
};