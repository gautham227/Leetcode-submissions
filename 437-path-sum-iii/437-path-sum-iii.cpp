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
    long long ans;
    
    void recur(TreeNode* node, long long cursum, long long target){
        if(cursum+node->val==target)ans++;
        if(node->left!=NULL)recur(node->left, cursum+node->val,target);
        if(node->right!=NULL)recur(node->right, cursum+ node->val, target);
        
        return;
    }
    
    void recur1(TreeNode* node, long long target){
        recur(node, 0, target);
        if(node->left!=NULL)recur1(node->left,target);
        if(node->right!=NULL)recur1(node->right,target);
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        
        if(root==NULL)return 0;
        ans=0;
        
        recur1(root, targetSum);
        
        return ans;
    }
};