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
    vector<int> ans;
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode* >q;
        q.push(root);
        q.push(NULL);
        TreeNode* cur;
        while(!q.empty()){
            cur=q.front();
            q.pop();
            if(cur==NULL)continue;
            if(cur->left!=NULL){
                q.push(cur->left);
            }
            if(cur->right!=NULL){
                q.push(cur->right);
            }
            if(q.front()==NULL){
                ans.push_back(cur->val);
                q.push(NULL);
                q.pop();
            }
        }
        return ans;
    }
};