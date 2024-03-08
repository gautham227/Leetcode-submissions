class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int> >dp(n, vector<int>(m, 0));
        int ans=0;
        dp[0][0]=grid[0][0];
        if(dp[0][0]<=k)ans++;
        for(int i=1;i<n;i++){
            dp[i][0]=dp[i-1][0]+grid[i][0];
            if(dp[i][0]<=k)ans++;
        }
        for(int i=1;i<m;i++){
            dp[0][i]=dp[0][i-1]+grid[0][i];
            if(dp[0][i]<=k)ans++;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+grid[i][j];
                if(dp[i][j]<=k)ans++;
            }
        }
        return ans;
    }
};