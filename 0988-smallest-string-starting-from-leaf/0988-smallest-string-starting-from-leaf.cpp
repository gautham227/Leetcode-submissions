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
    string ans="~";
    void dfs(TreeNode* node, string &s){
        if(node==NULL)return;
        if(node->left==NULL && node->right==NULL){
            s.push_back((char)('a'+(node->val)));
            reverse(s.begin(), s.end());
            if(ans>s){
                ans=s;
            }
            reverse(s.begin(), s.end());
            s.pop_back();
        }
        s.push_back((char)('a'+(node->val)));
        dfs(node->left, s);
        dfs(node->right, s);
        s.pop_back();
    }
    string smallestFromLeaf(TreeNode* root) {
        string s="";
        dfs(root,s);
        return ans;
    }
};