class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int cnt=0;
        int ind=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){cnt++; ind=nums.size()-i;}
        }
        if(nums[nums.size()-1]>nums[0])cnt++;
        if(cnt>1)return -1;
        return ind;
    }
};