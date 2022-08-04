class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n,m;
        n=grid.size(); // no of rows
        m=grid[0].size(); // no of columns
        vector<vector<int> >dp(n, vector<int>(m, -1));
        // in dp matrix it stores the min cost to reach i,j from 0,0
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0){dp[i][j]=grid[i][j];continue;}
                int l=INT_MAX, u=INT_MAX;
                if(i>=1)u=dp[i-1][j];
                if(j>=1)l=dp[i][j-1];
                dp[i][j]=min(l,u)+grid[i][j];
            }
        }
        return dp[n-1][m-1];
    }
};