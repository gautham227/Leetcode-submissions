class Solution {
public:
    
    int ans=INT_MAX;
    
    void dfs(int ind, map<int,vector<vector<int> > >& adj, set<int>& vis){
        if(vis.find(ind)!=vis.end())return;
        vis.insert(ind);
        for(auto &ele: adj[ind]){
            ans=min(ans, ele[1]);
            dfs(ele[0], adj, vis);
        }
        return;
    }
    
    int minScore(int n1, vector<vector<int>>& roads) {
        map<int,vector<vector<int>> >adj;
        int n=roads.size();
        for(int i=0;i<n;i++){
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        set<int> vis;
        dfs(1,adj,vis);
        return ans;
    }
};