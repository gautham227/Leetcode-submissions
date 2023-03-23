class Solution {
public:
    
    void dfs(int ind, vector<vector<int> >& adj, vector<bool>& vis){
        if(vis[ind])return;
        vis[ind]=true;
        for(auto ch: adj[ind]){
            dfs(ch,adj,vis);
        }
        return;
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int> >adj(n);
        for(auto ele: connections){
            adj[ele[0]].push_back(ele[1]);
            adj[ele[1]].push_back(ele[0]);
        }
        int len=connections.size();
        if(len<n-1)return -1;
        vector<bool> vis(n, false);
        int ans=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                ans++;
                dfs(i,adj,vis);
            }
        }
        return ans-1;
    }
};