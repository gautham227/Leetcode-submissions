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
    int minDepth(TreeNode* root) {
        if(root==NULL)return 0;
        
        queue<pair<TreeNode*,int> > q;
        q.push({root,1});
        while(!q.empty()){
            TreeNode* t=q.front().first;
            int d=q.front().second;
            q.pop();
            if(t->left==NULL && t->right==NULL)return d;
            if(t->left!=NULL)q.push({t->left,d+1});
            if(t->right!=NULL)q.push({t->right,d+1});
        }
        return 0;
    }
};