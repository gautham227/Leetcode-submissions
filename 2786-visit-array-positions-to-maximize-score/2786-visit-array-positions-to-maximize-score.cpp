class Solution {
public:
    
    long long recur(int ind, int parity, vector<int>& nums, int x, vector<vector<long long> > & dp){
        if(ind>=nums.size())return 0;
        if(dp[ind][parity]!=-1)return dp[ind][parity];
        
        long long cur=0;
        
        if(nums[ind]%2==parity)cur=1ll*nums[ind]+recur(ind+1,parity,nums,x,dp);
        else{
            cur=max(cur, nums[ind]-x+recur(ind+1,1-parity, nums,x,dp));
        }
        cur=max(cur, recur(ind+1,parity,nums,x,dp));
        return dp[ind][parity]=cur;
    }
    
    long long maxScore(vector<int>& nums, int x) {
        long long n=nums.size();
        vector<vector<long long> > dp(n+1,vector<long long> (2,-1));
        
        
        return nums[0]+recur(1,nums[0]%2,nums,x,dp);
    }
};