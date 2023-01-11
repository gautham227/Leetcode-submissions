class Solution {
public:
    
    int dfs(int node, int par, vector<vector<int> >& adj, vector<bool> hasapple){
        int ans=0;
        int cnt=0;
        for(auto child: adj[node]){
            if(child==par)continue;
            int val=dfs(child,node,adj,hasapple);
            ans+=val;
        }
        
        if(ans>0)ans+=1;
        else{
            if(hasapple[node])ans=1;
        }
        return ans;
    }
    
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int> >adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int ans1=dfs(0,-1,adj,hasApple);
        if(ans1==0)return 0;
        return 2*ans1-2;
    }
};