class Solution {
public:
    
    vector<vector<int>> ans;
    
    void recur(vector<int>& nums, int ind, vector<int>& cur){
        ans.push_back(cur);
        if(ind>=nums.size())return;
        for(int i=ind;i<nums.size();i++){
            if(i!=ind && nums[i]==nums[i-1])continue;
            cur.push_back(nums[i]);
            recur(nums,i+1,cur);
            cur.pop_back();
        }
        return;
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> cur;
        recur(nums,0,cur);
        return ans;
    }
};