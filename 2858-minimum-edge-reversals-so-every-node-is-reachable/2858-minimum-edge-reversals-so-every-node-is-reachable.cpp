class Solution {
public:
    
    int dfs1(int node, int par, vector<vector<vector<int> > >& adj){
        int cur=0;
        for(auto ele: adj[node]){
            if(ele[0]==par)continue;
            cur+=ele[1];
            cur+=dfs1(ele[0], node, adj);
        }
        return cur;
    }
    
    void dfs2(int node, int par, vector<int>& ans, unordered_set<long long>& us, vector<vector<vector<int> > >& adj){
        ans[node]=ans[par];
        if(us.find(1ll*par*1000000000+node)!=us.end())ans[node]++;
        else ans[node]--;
        for(auto ele: adj[node]){
            if(ele[0]==par)continue;
            dfs2(ele[0], node, ans, us, adj);
        }
    }
    
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<int> ans(n);
        unordered_set<long long> us;
        
        vector<vector<vector<int> > > adj(n);
        for(auto &ele: edges){
            adj[ele[0]].push_back({ele[1],0});
            adj[ele[1]].push_back({ele[0],1});
            us.insert(1ll*ele[0]*1000000000+ele[1]);
        }
        ans[0]=dfs1(0,-1,adj);
        for(auto ele: adj[0]){
            dfs2(ele[0], 0, ans, us, adj);
        }
        return ans;
    }
};