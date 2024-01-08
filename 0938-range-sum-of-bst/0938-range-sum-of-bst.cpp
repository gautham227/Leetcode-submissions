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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==NULL)return 0;
        int cur=0;
        cur=rangeSumBST(root->left,low,high);
        cur+=rangeSumBST(root->right,low,high);
        if(root->val>=low and root->val<=high)cur+=root->val;
        return cur;
    }
};