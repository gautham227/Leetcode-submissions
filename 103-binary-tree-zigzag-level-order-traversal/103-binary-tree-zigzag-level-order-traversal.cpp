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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)return {};
        queue<TreeNode* > q;
        q.push(root);
        q.push(NULL);
        int cnt=0;
        vector<int> v;
        vector<vector<int> >ans;
        bool dir=0;
        while(!q.empty()){
            TreeNode* cur=q.front();
            if(cur==NULL){
                cnt++;
                if(v.size()==0)break;
                else{
                    if(dir){
                        reverse(v.begin(), v.end());
                    }
                    ans.push_back(v);
                    v.clear();
                }
                dir=!dir;
                q.push(NULL);
            }
            else{
                v.push_back(cur->val);
                int cnt1=0;
                if(cur->left!=NULL){q.push((cur->left));cnt1++;}
                if(cur->right!=NULL){q.push((cur->right));cnt1++;}
            }
            q.pop();
        }
        if(v.size()!=0){
            if(dir==1)reverse(v.begin(), v.end());
            ans.push_back(v);
        }
        return ans;
    }
};