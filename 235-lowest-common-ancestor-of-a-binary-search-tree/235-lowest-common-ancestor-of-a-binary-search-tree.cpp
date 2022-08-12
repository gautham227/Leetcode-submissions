/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool recur(TreeNode* root,TreeNode* p, vector<TreeNode*> &v){
        if(root==NULL){
            return false;
        }
        if(root==p){
            v.push_back(root);
            return true;
        }
        bool l=recur(root->left,p,v);
        bool r=recur(root->right,p,v);
        if(l||r){
            v.push_back(root);
        }
        return l||r;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> v1,v2;
        recur(root,p,v1);
        recur(root,q,v2);
        reverse(v1.begin(),  v1.end());
        reverse(v2.begin(),  v2.end());
        // for(int i=0;i<v1.size();i++){
        //     cout<<v1[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0;i<v2.size();i++){
        //     cout<<v2[i]<<" ";
        // }
        // cout<<endl;
        TreeNode* ans=NULL;
        for(int i=0;i<min(v1.size(),v2.size());i++){
            if(v1[i]!=v2[i]){
                break;
            }
            ans=v1[i];
        }
        return ans;
    }
};