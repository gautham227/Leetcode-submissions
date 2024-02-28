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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode* > cur;
        cur.push(root);
        cur.push(NULL);
        bool flag=true;
        int ans=0;
        while(cur.size()>0){
            if(flag && cur.front()==NULL)break;
            TreeNode* node=cur.front();
            cur.pop();
            if(node==NULL){
                flag=true;
                cur.push(NULL);
                continue;
            }
            if(flag){
                ans=node->val;
                flag=false;
            }
            if(node->left!=NULL)cur.push(node->left);
            if(node->right!=NULL)cur.push(node->right);
        }
        return ans;
    }
};