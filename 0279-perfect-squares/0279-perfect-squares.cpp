class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+2, INT_MAX);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=100;j++){
                if(i-j*j<0)break;
                dp[i]=min(dp[i], 1+dp[i-j*j]);
            }
        }
        return dp[n];
    }
};