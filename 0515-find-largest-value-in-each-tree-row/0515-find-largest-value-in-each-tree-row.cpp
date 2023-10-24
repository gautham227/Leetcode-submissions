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
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL)return {};
        vector<int> ans;
        int curmin=INT_MIN;
        queue<TreeNode*> nodes;
        nodes.push(root);
        nodes.push(NULL);
        int cntr=0;
        while(nodes.size()>0){
            TreeNode* curele=nodes.front();
            nodes.pop();
            if(curele==NULL){
                if(cntr==0){
                    cntr++;
                    nodes.push(NULL);
                    ans.push_back(curmin);
                    curmin=INT_MIN;
                }
                else{
                    break;
                }
            }
            else{
                cntr=0;
                curmin=max(curmin, curele->val);
                if(curele->left!=NULL)nodes.push(curele->left);
                if(curele->right!=NULL)nodes.push(curele->right);
            }
        }
        return ans;
    }
};