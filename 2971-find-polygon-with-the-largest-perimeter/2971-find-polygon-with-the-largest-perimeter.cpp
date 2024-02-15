class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long sum=accumulate(nums.begin(), nums.end(), 0*1ll);
        int ind=nums.size()-1;
        while(ind>-1 && sum-nums[ind]<=nums[ind]){
            sum-=nums[ind];
            ind--;
        }
        if(ind+1<3)return -1;
        return sum;
    }
};