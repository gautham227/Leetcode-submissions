class Solution {
public:
    
    int n,m;
    
    int dfs(int x, int y, vector<vector<int> >& grid){
        if(x<0 || y<0 || x>=n || y>=m || grid[x][y]==0)return 0;
        int ans=0;
        int temp=grid[x][y];
        grid[x][y]=0;
        
        ans=max(ans,temp+dfs(x+1,y,grid));
        ans=max(ans,temp+dfs(x,y+1,grid));
        ans=max(ans,temp+dfs(x-1,y,grid));
        ans=max(ans,temp+dfs(x,y-1,grid));
        
        grid[x][y]=temp;
        return ans;
        
    }
        
    int getMaximumGold(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans, dfs(i,j,grid));
            }
        }
        return ans;
    }
};