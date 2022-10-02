class Solution {
public:
    int mod=1000000000+7;
    long long recur(int ind,int n,int k, int tar, vector<vector<long long> >&dp){
        if(tar<0)return 0;
        if(ind==n){
            if(tar==0)return 1;
            return 0;
        }
        if(tar==0)return 0;
        if(dp[ind][tar]!=-1)return dp[ind][tar];
        long long cur=0;
        for(int i=1;i<=k;i++){
            cur+=recur(ind+1,n,k,tar-i,dp);
            cur%=mod;
        }
        return dp[ind][tar]=cur;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<long long> >dp(31, vector<long long>(1001,-1));
        return recur(0,n,k,target,dp)%mod;
    }
};