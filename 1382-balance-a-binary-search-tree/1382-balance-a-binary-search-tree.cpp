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
    
    vector<int> cur;
    
    void dfs(TreeNode* node){
        if(node==NULL)return;
        dfs(node->left);
        cur.push_back(node->val);
        dfs(node->right);
        return;
    }
    
    TreeNode* constructbst (int l, int r){
        if(r<l)return NULL;
        if(l==r)return new TreeNode(cur[l]);
        return new TreeNode(cur[(l+r)/2], constructbst(l,(l+r)/2 - 1) , constructbst((l+r)/2+1,r));
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        dfs(root);
        return constructbst(0,cur.size()-1);
    }
};