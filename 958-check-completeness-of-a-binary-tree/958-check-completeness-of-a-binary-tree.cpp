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
    map<int,int> mp;
    int h1;
    bool ans;
    void dfs(TreeNode* root, int h){
        if(root==NULL)return;
        if(root->left==NULL && root->right==NULL){
            if(h>h1){
                ans=false;
            }
            h1=min(h,h1);
        }
        if(root->left==NULL && root->right!=NULL)ans=false;
        mp[h]++;
        dfs(root->left,h+1);
        dfs(root->right,h+1);
        if(root->left!=NULL && root->right==NULL)h1=h;
        return;
    }
    
    bool isCompleteTree(TreeNode* root) {
        h1=(int)1e9;
        ans=true;
        dfs(root,0);
        int last=1;
        int sz=mp.size();
        cout<<sz<<endl;
        int cnt=0;
        for(auto ele: mp){
            if(cnt!=sz-1 && last!=ele.second)return false;
            last*=2;
            cnt++;
        }
        cout<<ans<<endl;
        return ans;
    }
};