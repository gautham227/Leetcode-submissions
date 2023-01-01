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
    bool recur(TreeNode* root, long long mi, long long ma){
        if(root==NULL)return true;
        if(root->val<=mi || root->val>=ma )return false;
        return recur(root->left, mi, root->val) && recur(root->right, root->val, ma);
    }
    bool isValidBST(TreeNode* root) {
        return recur(root,-1e18, 1e18);
    }
};