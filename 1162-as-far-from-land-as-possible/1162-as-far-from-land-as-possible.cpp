#define maxv(a) *max_element(a.begin(), a.end())

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        int cnt1=0;
        vector<vector<int> >v(n*n+1);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i-1>-1)v[i*n+j].push_back((i-1)*n+j);
                if(i+1<n)v[i*n+j].push_back((i+1)*n+j);
                if(j-1>-1)v[i*n+j].push_back(i*n+j-1);
                if(j+1<n)v[i*n+j].push_back(i*n+j+1);
                if(grid[i][j]==1){v[n*n].push_back(i*n+j);cnt1++;}
            }
        }
        
        if(cnt1==0 || cnt1==n*n)return -1;
        
        vector<int> level((n+1)*(n+1),0);
        queue<int> q;
        int v1=n*n;
        q.push(v1);
        level[v1]=0;
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            for(int child : v[cur]){
                if(level[child]!=0){
                    continue;
                }
                q.push(child);
                // vis[child]=1;
                level[child]=level[cur]+1;
            }
        }
        
        return maxv(level)-1;
    }
};