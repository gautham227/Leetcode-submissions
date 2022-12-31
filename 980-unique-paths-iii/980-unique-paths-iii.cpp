class Solution {
public:
    
    int countpaths(int x, int y, vector<vector<int> >& grid, vector<vector<bool> > &vis, int n, int m, int cnt, int reqd, vector<pair<int,int> >& movements){
        if(x<0 || y<0 || x>=n || y>=m || grid[x][y]==-1 || vis[x][y]==true)return 0;
        vis[x][y]=true;
        cnt++;
        if(grid[x][y]==2){
            vis[x][y]=false;
            if(cnt==reqd)return 1;
            return 0;
        }
        
        int ans=0;
        
        for(int i=0;i<4;i++){
            ans+=countpaths(x+movements[i].first, y+movements[i].second, grid, vis, n, m, cnt, reqd, movements);
        }
        
        cnt--;
        vis[x][y]=false;
        
        return ans;
        
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int cnt=0;
        int n=grid.size();
        int m=grid[0].size();
        int x1=-1, y1=-1;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=-1)cnt++;
                if(grid[i][j]==1){
                    x1=i;
                    y1=j;
                }
            }
        }
        
        vector<vector<bool> >vis(n, vector<bool>(m,false));
        vector<pair<int,int> >movements={{0,-1},{0,1},{-1,0},{1,0}};
        return countpaths(x1,y1,grid,vis,n,m,0,cnt,movements);
    }
};