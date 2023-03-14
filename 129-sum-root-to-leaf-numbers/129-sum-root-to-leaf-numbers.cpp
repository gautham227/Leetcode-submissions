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
    int cur=0;
    int ans=0;
    int sumNumbers(TreeNode* root) {
        if(root==NULL)return 0;
        cur*=10;
        cur+=root->val;
        if(root->left==NULL && root->right==NULL)ans+=cur;
        if(root->left!=NULL)sumNumbers(root->left);
        if(root->right!=NULL)sumNumbers(root->right);
        cur/=10;
        return ans;
    }
};