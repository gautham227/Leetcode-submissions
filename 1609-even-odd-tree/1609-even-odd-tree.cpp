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
    bool isEvenOddTree(TreeNode* root) {
        bool ans=true;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        bool odd=false;
        
        bool lastnull=true;
        int maxi=INT_MAX, mini=INT_MIN;
        while(q.size()>0){
            TreeNode* cur=q.front();
            q.pop();
            if(cur==NULL && lastnull==true){
                break;
            }
            if(cur==NULL){
                lastnull=true;
                odd=1-odd;
                maxi=INT_MAX;
                mini=INT_MIN;
                q.push(NULL);
                continue;
            }
            lastnull=false;
            
            if(odd){
                if(((cur->val)%2)!=0 || cur->val>=maxi){
                    ans=false;
                    break;
                }
                maxi=cur->val;
            }
            else{
                if(((cur->val)%2)!=1 || cur->val<=mini){
                    ans=false;
                    break;
                }
                mini=cur->val;
            }
            if(cur->left!=NULL)q.push(cur->left);
            if(cur->right!=NULL)q.push(cur->right);
        }
        return ans;
        
    }
};