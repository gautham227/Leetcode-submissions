class Solution {
public:
    // a->0, e-> 1, i-> 2, o->3, u->4
    
    long long recur(int n, int cur, vector<vector<long long> >&dp){
        if(n==1)return 1;
        if(dp[n][cur]!=-1)return dp[n][cur];
        if(cur==0){
            dp[n][cur]=recur(n-1,1,dp);
            dp[n][cur]%=(1000000000+7);
        }
        else if(cur==1){
            dp[n][cur]=recur(n-1,0,dp)+recur(n-1,2,dp);
            dp[n][cur]%=(1000000000+7);
        }
        else if(cur==2){
            dp[n][cur]=recur(n-1,0,dp)+recur(n-1,1,dp)+recur(n-1,3,dp)+recur(n-1,4,dp);
            dp[n][cur]%=(1000000000+7);
        }
        else if(cur==3){
            dp[n][cur]=recur(n-1,2,dp)+recur(n-1,4,dp);
            dp[n][cur]%=(1000000000+7);
            
        }
        else if(cur==4){
            dp[n][cur]=recur(n-1,0,dp);
            dp[n][cur]%=(1000000000+7);
        }
        return dp[n][cur];
    }
    
    int countVowelPermutation(int n) {
        vector<vector<long long> >dp(n+1,vector<long long>(5,-1));
        long long ans=0;
        for(int i=0;i<5;i++){
            ans+=recur(n,i,dp);
            ans%=(1000000000+7);
        }
        return (int)ans;
    }
};