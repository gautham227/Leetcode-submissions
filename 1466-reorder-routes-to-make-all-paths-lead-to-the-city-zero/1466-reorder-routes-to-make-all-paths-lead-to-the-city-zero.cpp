class Solution {
public:
    
    int dfs(int cur, vector<vector<vector<int > > >& adj, int par){
        int ans=0;
        for(auto ele: adj[cur]){
            if(ele[0]==par)continue;
            ans+=ele[1];
            ans+=dfs(ele[0],adj,cur);
        }
        return ans;
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<vector<int> > >adj(n);
        for(auto ele: connections){
            adj[ele[0]].push_back({ele[1],0});
            adj[ele[1]].push_back({ele[0],1});
        }
        return n-1-dfs(0,adj,-1);
    }
};