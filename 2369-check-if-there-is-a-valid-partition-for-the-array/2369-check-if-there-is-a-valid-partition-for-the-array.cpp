class Solution {
public:
    int n;
    int recur(int ind, vector<int>& nums, vector<int>& dp){
        
        if(ind>=nums.size())return 1;
        if(dp[ind]!=-1)return dp[ind];
        int x=-1, y=-1, z=-1;
        if(ind+2<n){
            if((nums[ind]==nums[ind+1]) && (nums[ind]==nums[ind+2])){
                x=recur(ind+3,nums,dp);
            }
            if(x==1)return dp[ind]=1;
            if((nums[ind+1]==nums[ind]+1) && (nums[ind+2]==nums[ind]+2)){
                z=recur(ind+3,nums,dp);
            }
            if(z==1)return dp[ind]=1;
        }
        if(ind+1<n){
            if(nums[ind]==nums[ind+1]){
                y=recur(ind+2,nums,dp);
            }
            if(y==1)return dp[ind]=1;
        }
        return dp[ind]=0;
    }
    
    bool validPartition(vector<int>& nums) {
        n=nums.size();
        vector<int>dp(n+1,-1);
        if(recur(0,nums,dp)==1)return true;
        return false;
    }
};