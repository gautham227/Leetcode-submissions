class Solution {
public:
    
    int recur(int ind, vector<int> & cost, vector<int>& dp){
        if(ind>=cost.size())return 0;
        if(dp[ind]!=-1)return dp[ind];
        return dp[ind]=cost[ind]+min(recur(ind+1,cost,dp), recur(ind+2,cost,dp));
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(),-1);
        return min(recur(0,cost,dp),recur(1,cost,dp));
    }
};