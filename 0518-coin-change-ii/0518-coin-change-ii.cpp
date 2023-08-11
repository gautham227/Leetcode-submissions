class Solution {
public:
    int recur(int ind, int req, vector<int>& coins, vector<vector<int> > &dp){
        if(ind==0){
            if(req%coins[ind]==0)return 1;
            return 0;
        }
        if(dp[ind][req]!=-1)return dp[ind][req];
        int take=0, ntake=0;
        ntake=recur(ind-1, req, coins, dp);
        if(coins[ind]<=req)take=recur(ind, req-coins[ind], coins, dp);
        return dp[ind][req]=take+ntake;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int> >dp(n, vector<int> (amount+1,-1));
        return recur(n-1,amount,coins, dp);
    }
};