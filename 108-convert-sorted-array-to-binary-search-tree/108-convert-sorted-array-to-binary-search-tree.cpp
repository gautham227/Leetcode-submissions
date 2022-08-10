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
    TreeNode* recur(vector<int>& nums, int l, int h){
        if(h<l)return NULL;
        int mid=(l+h)/2;
        TreeNode* ele=new TreeNode(nums[mid],recur(nums,l,mid-1),recur(nums,mid+1,h));
        return ele;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return recur(nums,0,nums.size()-1);
    }
};