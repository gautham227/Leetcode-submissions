class Solution {
public:
    
    bool isvalid(int x, int y, int n, int m){
        if(x<0 || y<0 || x>=n || y>=m)return false;
        return true;
    }
    
    bool check(int val, vector<vector<int> >& move, vector<vector<int>> & safeness){
        int n=safeness.size();
        int m=safeness[0].size();
        if(safeness[0][0]<val)return false;
        vector<vector<bool> >vis(n, vector<bool>(m, false));
        vis[0][0]=true;
        queue<vector<int> >q;
        q.push({0,0});
        while(q.size()>0){
            int curx=(q.front())[0];
            int cury=(q.front())[1];
            q.pop();
            for(auto &ele: move){
                int newx=curx+ele[0];
                int newy=cury+ele[1];
                if(isvalid(newx, newy, n, m) && vis[newx][newy]==false && safeness[newx][newy]>=val){
                    vis[newx][newy]=true;
                    q.push({newx, newy});
                }
            }
        }
        return vis[n-1][m-1];
    }
    
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        // here we will first find the safeness factor associated with each cell using multi source bfs
        queue<vector<int> > q;
        vector<vector<int> >safeness(n, vector<int>(m, -1));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    safeness[i][j]=0;
                    q.push({i,j,0});
                }
            }
        }
        vector<vector<int> > move {{0,1},{1,0},{0,-1},{-1,0}};
        while(!q.empty()){
            vector<int> cur=q.front();
            q.pop();
            for(auto &ele: move){
                int newx=cur[0]+ele[0];
                int newy=cur[1]+ele[1];
                if(isvalid(newx, newy, n, m) && safeness[newx][newy]==-1){
                    safeness[newx][newy]=1+cur[2];
                    q.push({newx,newy,safeness[newx][newy]});
                }
            }
        }
        
        // now we can determine the max safeness factor using binary search
        
        int r=400, l=0;
        while(r-l>1){
            int mid=l+(r-l)/2;
            if(check(mid, move, safeness)){
                l=mid;
            }
            else{
                r=mid-1;
            }
        }
        if(check(r,move,safeness)){
            return r;
        }
        return l;
    }
};