class Solution {
public:
    
    int dp[71][71][71];
    
    int recur(int r, int c1, int c2, vector<vector<int>>& grid, int& n, int& m ){
        if(r>=n)return 0;
        if(c1>=m || c1<0 || c2>=m || c2<0)return 0;
        if(dp[r][c1][c2]!=-1)return dp[r][c1][c2];
        int ans=0;
        int cur=0;
        if(c1==c2)cur+=grid[r][c1];
        else cur+=grid[r][c1]+grid[r][c2];
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                ans=max(ans,cur+recur(r+1,c1+i,c2+j,grid,n,m));
            }
        }
        return dp[r][c1][c2]=ans;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int n=grid.size();
        int m=grid[0].size();
        return recur(0,0,m-1,grid,n,m);
    }
};