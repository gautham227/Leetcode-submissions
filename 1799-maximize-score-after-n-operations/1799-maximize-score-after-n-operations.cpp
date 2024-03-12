class Solution {
public:
    
    int recur(int mask, vector<int>& nums, vector<int>& dp){
        if(mask==((1<<(2*nums.size()))-1))return 0;
        if(dp[mask]!=-1)return dp[mask];
        int ans=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if((mask&(1<<i))>0 || (mask&(1<<j))>0)continue;
                ans=max(ans, ((__builtin_popcount(mask)/2 + 1) * __gcd(nums[i], nums[j]))+recur(mask | (1<<i) | (1<<j), nums, dp));
            }
        }
        return dp[mask]=ans;
    }
    
    int maxScore(vector<int>& nums) {
        vector<int> dp((1<<(nums.size()))+5, -1);
        return recur(0, nums, dp);
    }
};