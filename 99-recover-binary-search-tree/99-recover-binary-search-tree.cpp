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
    void recur(TreeNode* root, vector<int>& v){
        if(root==NULL)return;
        recur(root->left, v);
        v.push_back(root->val);
        recur(root->right, v);
        return;
    }
    void rep(TreeNode* root, int ori1, int ori2){
        if(root==NULL)return;
        if(root->val==ori1)root->val=ori2;
        else if(root->val==ori2)root->val=ori1;
        rep(root->left, ori1, ori2);
        rep(root->right, ori1, ori2);
        return;
    }
    void recoverTree(TreeNode* root) {
        vector<int> v;
        recur(root, v);
        int ori1, ori2, f=0;
        for(int i=1;i<v.size();i++){
            if(v[i]<v[i-1]){
                ori1=v[i];
            }
        }  
        for(int i=0;i<v.size();i++){
            if(v[i]>ori1){
                ori2=v[i];
                break;
            }
        }
        rep(root, ori1, ori2);
        return;
    }
};