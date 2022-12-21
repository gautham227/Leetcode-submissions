class Solution {
public:
    int vis[2005];
    bool ispossible(vector<vector<int> > &adj, int node, int last){
        vis[node]=1-last;
        bool ret=true;
        for(auto child: adj[node]){
            if(vis[child]==-1)ret=ret&&(ispossible(adj,child,1-last));
            else ret=ret&&(vis[child]==last);
        }
        return ret;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int> > adj(n+1);
        for(int i=0;i<dislikes.size();i++){
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
        }
        // memset(vis,-1,sizeof(vis));
        bool ans=true;
        for(int i=1;i<=n;i++){
            memset(vis,-1,sizeof(vis));
            if(vis[i]==-1)ans=ans&&(ispossible(adj,i,0));
        }
        return ans;
    }
};