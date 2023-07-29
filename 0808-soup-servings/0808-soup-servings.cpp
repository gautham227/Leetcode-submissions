class Solution {
public:
    
    double recur(int a, int b, vector<vector<double> >& dp){
        if(a<=0 && b<=0)return 0.5;
        if(a<=0)return 1;
        if(b<=0)return 0;
        if(dp[a][b]>=0)return dp[a][b];
        return dp[a][b]=0.25*(recur(a-4,b, dp)+recur(a-3, b-1, dp)+recur(a-2,b-2, dp)+recur(a-1,b-3,dp));
    }
    
    double soupServings(int n) {
        if(n>=5000)return 1;
       int serve=(n+24)/25;
       vector<vector <double > >dp(serve+1, vector<double>(serve+1, -1));
        return recur(serve, serve, dp);
    }
};