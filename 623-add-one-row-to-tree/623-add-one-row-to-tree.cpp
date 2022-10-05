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
    void recur(TreeNode* node, int val, int depth, int cur){
        if(cur==depth-1){
            TreeNode* x=new TreeNode(val, node->left, NULL);
            TreeNode* y=new TreeNode(val, NULL, node->right);
            node->left=x;
            node->right=y;
            return;
        }
        if(node->left!=NULL)recur(node->left,val,depth,cur+1);
        if(node->right!=NULL)recur(node->right,val,depth,cur+1);
        return;
        
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* x=new TreeNode(val,root,NULL);
            return x;
        }
        recur(root,val,depth,1);
        return root;
    }
};