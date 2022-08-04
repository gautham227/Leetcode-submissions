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
    bool ans=1;
    void dfs(TreeNode* r1,TreeNode* r2){
        if(r1==NULL && r2==NULL){
            return;
        }
        if(r1==NULL || r2==NULL){
            ans=0;
            return;
        }
        if(r1->val!=r2->val){
            ans=0;
            return;
        }
        dfs(r1->left,r2->right);
        dfs(r1->right, r2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)return true;
        dfs(root->left, root->right);
        return ans;
    }
};