class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
        if(nums.size()<=2)return true;
        int maxi=0;
        for(int i=1;i<nums.size();i++){
            maxi=max(maxi, nums[i-1]+nums[i]);
        }
        return (maxi>=m);
    }
};