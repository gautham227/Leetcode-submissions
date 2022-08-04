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
    int ans=INT_MIN;
    int recur(TreeNode* root){
        if(root->left==NULL && root->right==NULL){ans=max(ans,root->val); return root->val;}
        int l=0, r=0;
        if(root->left!=NULL)l=max(recur(root->left),l);
        if(root->right!=NULL)r=max(recur(root->right),r);
        // cout<<ans<<endl;
        ans=max(ans,(root->val, max(root->val+l, max(root->val+r, root->val+l+r))));
        return max(root->val, max(root->val+l,root->val+r));
    }
    int maxPathSum(TreeNode* root) {
        recur(root);
        return ans;
    }
};