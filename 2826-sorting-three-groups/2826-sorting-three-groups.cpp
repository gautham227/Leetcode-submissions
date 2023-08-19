class Solution {
public:
    
    int ans;
    
    int recur(int ind, int last, vector<int> & nums, vector<vector<int> >& dp){
        if(ind==nums.size()){
            return 0;
        }
        if(dp[ind][last]!=-1)return dp[ind][last];
        int curval=INT_MAX;
        for(int val=last;val<=3;val++){
            int x=0;
            if(nums[ind]!=val)x=1;
            curval=min(curval, recur(ind+1,val,nums,dp)+x);
        }
        return dp[ind][last]=curval;
    }
    
    int minimumOperations(vector<int>& nums) {
       int n=nums.size();
        ans=10000000;
        vector<vector<int> > dp(n, vector<int>(4, -1));
        return recur(0,1,nums,dp);
    }
};