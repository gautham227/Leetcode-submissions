class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lo=0, hi=nums.size()/2, mid;
        while(lo<hi){
            mid=(lo+hi)/2;
            if(nums[2*mid]!=nums[2*mid+1])hi=mid;
            else lo=mid+1;
        }
        return nums[2*lo];
    }
};