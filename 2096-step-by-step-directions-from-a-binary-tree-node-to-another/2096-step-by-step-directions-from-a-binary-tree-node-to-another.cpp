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
    string ans;
    void dfs(TreeNode* node, int val, string& s){
        if(node==NULL)return;
        
        if(node->val==val){
            ans=s;
        }
        
        s.push_back('L');
        
        dfs(node->left, val, s);
        s[s.size()-1]='R';
        dfs(node->right, val, s);
        s.pop_back();
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        
        string a="";
        string temp="";
        dfs(root, startValue, temp);
        string cur1=ans;
        
        temp.clear();
        
        dfs(root, destValue, temp);
        string cur2=ans;
        
        int common=0;
        
        for(int i=0;i<min(cur1.size(), cur2.size());i++){
            if(cur1[i]==cur2[i]){
                common++;
            }
            else{
                break;
            }
        }
        
        for(int i=0;i<cur1.size()-common;i++){
            a+="U";
        }
        for(int i=common;i<cur2.size();i++)a.push_back(cur2[i]);
        return a;
    }
};