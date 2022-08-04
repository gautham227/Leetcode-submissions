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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL)return {};
        vector<vector<int> >v;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> cur;
        // cur.push_back(root->val);
        while(!q.empty()){
            TreeNode* c=q.front();
            q.pop();
            if(c==NULL){
                v.push_back(cur);
                cur.clear();
                if(q.size()>0)q.push(NULL);
                continue;
            }
            cur.push_back(c->val);
            if(c->left!=NULL){
                q.push(c->left);
            }
            if(c->right!=NULL){
                q.push(c->right);
            }
        }
        return v;
    }
};