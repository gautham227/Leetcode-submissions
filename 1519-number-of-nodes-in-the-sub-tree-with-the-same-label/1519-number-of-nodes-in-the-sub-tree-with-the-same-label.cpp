class Solution {
public:
    
    vector<int> dfs(int node, int par, vector<vector<int> >&adj, vector<int>& ans, string& labels){
        vector<int> cur(26,0);
        cur[labels[node]-'a']++;
        for(auto child: adj[node]){
            if(child==par)continue;
            vector<int> ch;
            ch=dfs(child,node,adj,ans,labels);
            for(int i=0;i<26;i++){
                cur[i]+=ch[i];
            }
        }
        ans[node]=cur[labels[node]-'a'];
        return cur;
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> ans(n,0);
        vector<vector<int> >adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(0,-1,adj,ans,labels);
        return ans;
    }
};