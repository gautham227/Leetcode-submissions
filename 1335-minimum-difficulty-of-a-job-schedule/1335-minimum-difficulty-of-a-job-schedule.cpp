class Solution {
public:
    int minDifficulty(vector<int>& jd, int d) {
        // dp[ind][no of days left]
        if(d>jd.size())return -1;
        int n=jd.size();
        vector<vector<int> >dp(n+2, vector<int>(d+2,1000000000+7));
        int ma=0;
        for(int i=n-1;i>=0;i--){
            ma=max(ma, jd[i]);
            dp[i][1]=ma;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=2;j<=d;j++){
                ma=0;
                for(int k=i;k<n;k++){
                    ma=max(ma, jd[k]);
                    dp[i][j]=min(dp[i][j], ma+dp[k+1][j-1]);
                }
            }
        }
        
        return dp[0][d];
    }
};