class Solution {
public:
    
    vector<vector<int>> ans;
    
    void recur(vector<int>& nums, int ind, vector<int> &temp){
        if(ind==nums.size()){ans.push_back(temp);return;}
        recur(nums,ind+1,temp);
        temp.push_back(nums[ind]);
        recur(nums,ind+1,temp);
        temp.pop_back();
        return;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        recur(nums,0,v);
        return ans;
    }
};