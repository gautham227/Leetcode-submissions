class Solution {
public:
    vector<set<int> >ans;
    
    std::vector<int> vis;
    std::vector<int> adj[1002];
    
    void dfs(int ele, int n){
        if(vis[n]!=0)return;
        vis[n]=1;
        for(auto x: adj[n]){
            ans[ele].insert(x);
            dfs(ele, x);
        }
    }
    
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vis.resize(1002);
        for(int i=0;i<vis.size();i++)vis[i]=0;
        for(int i=0;i<edges.size();i++){
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        ans.resize(n);
        for(int i=0;i<n;i++){
            for(int i=0;i<vis.size();i++){
                vis[i]=0;
            }
            dfs(i,i);
        }
        vector<vector<int>> a;
        for(int i=0;i<n;i++){
            vector<int> v1;
            for(auto it=ans[i].begin(); it!=ans[i].end(); it++){
                v1.push_back(*it);
            }
            a.push_back(v1);
        }
        cout<<endl;
        return a;
    }
};