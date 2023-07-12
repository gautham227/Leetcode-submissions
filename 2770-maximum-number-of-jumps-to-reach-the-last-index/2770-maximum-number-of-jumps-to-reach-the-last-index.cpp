class Solution {
public:
    
    long long recur(int ind, vector<int>& nums, long long tar, vector<long long>& dp){
        if(ind>=nums.size()-1)return 0;
        if(dp[ind]!=-1)return dp[ind];
        int cur=-10000000;
        for(int i=ind+1;i<nums.size();i++){
            if(abs(nums[i]-nums[ind])<=tar){
                dp[ind]=max(dp[ind], 1+recur(i, nums, tar, dp));
            }
        }
        if(dp[ind]<0)return dp[ind]=-10000000;
        return dp[ind];
    }
    
    int maximumJumps(vector<int>& nums, int target) {
        int tar=target;
        int n=nums.size();
        vector<long long> dp(n,-1);
        long long ans=recur(0, nums, tar, dp);
        if( ans < 0)return -1;
        return ans;
    }
};