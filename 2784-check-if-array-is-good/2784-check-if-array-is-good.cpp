class Solution {
public:
    bool isGood(vector<int>& nums) {
        if(nums.size()<2)return false;
        sort(nums.begin(), nums.end());
        bool flag=true;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]!=i+1)flag=false;
        }
        if(nums[nums.size()-1]!=nums[nums.size()-2])flag=false;
        return flag;
    }
};