class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& v) {
        int n=v.size(),m=v[0].size();
        vector<vector<int> >dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]==1){dp[i][j]=0;continue;}
                if(i==0 && j==0){dp[i][j]=1;continue;}
                int u=0,l=0;
                if(i-1>-1)u=dp[i-1][j];
                if(j-1>-1)l=dp[i][j-1];
                dp[i][j]=u+l;
            }
        }
        return dp[n-1][m-1];
    }
};