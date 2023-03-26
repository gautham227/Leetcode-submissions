class Solution {
public:
    
    vector<int> vis;
    int ans=-1;
    unordered_map<int,int> mp;
    void dfs(int ind, vector<int>&edges, int t){
        if(ind==-1 || vis[ind]==1)return;
        if(vis[ind]==2){
            ans=max(ans,t-mp[ind]);
            return;
        }
        mp[ind]=t;
        vis[ind]=2;
        dfs(edges[ind],edges,t+1);
        vis[ind]=1;
        return;
    }
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vis.assign(n,0);
        for(int i=0;i<n;i++){
            if(vis[i])continue;
            dfs(i,edges,0);
        }
        return ans;
    }
};