class Solution {
public:
    int dp[101][101][201];
    int n,m;
    int recur(int x, int y, int cnt, vector<vector<char> >& grid){
        // cout<<x<<" "<<y<<" "<<cnt<<endl;
        if(x>=n || y>=m || x<0 || y<0)return 0;
        if(cnt<0)return 0;
        if(dp[x][y][cnt]!=-1)return dp[x][y][cnt];
        if(x==n-1 && y==m-1){
            if(grid[x][y]==')' && cnt==1){return 1;}
            return 0;
        }
        int cnt1=cnt;
        if(grid[x][y]=='(')cnt1++;
        else cnt1--;
        return dp[x][y][cnt]=recur(x+1,y,cnt1,grid)|| recur(x,y+1,cnt1,grid);
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
        memset(dp, -1, sizeof dp);
        int ans=recur(0,0,0,grid);
        if(ans>=1)return true;
        return false;
    }
};