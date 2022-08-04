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
    unordered_map<int, int> mp;
    TreeNode* build(int &ind, int l, int r, vector<int>& preorder, vector<int>& inorder){
        if(r<l)return NULL;
        // cout<<l<<" "<<r<<endl;
        TreeNode* node=new TreeNode(preorder[ind]);
        int val=preorder[ind];
        ind++;
        node->left=build(ind,l,mp[val]-1,preorder, inorder);
        node->right=build(ind,mp[val]+1,r,preorder, inorder);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        int root=0;
        return build(root,0,inorder.size()-1,preorder,inorder);
    }
};