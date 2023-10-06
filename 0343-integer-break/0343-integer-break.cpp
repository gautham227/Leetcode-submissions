class Solution {
public:
    long long recur(int ind, vector<long long>& dp){
        if(ind<=1)return 1;
        if(dp[ind]!=-1)return dp[ind];
        long long cur=ind;
        for(long long i=0;i<ind;i++){
            cur=max(cur, (ind-i)*recur(i,dp));
        }
        return dp[ind]=cur;
    }
    int integerBreak(int n) {
       vector<long long> dp(60,-1);
        if(n<=3)return n-1;
        recur(n,dp);
        return dp[n];
    }
};