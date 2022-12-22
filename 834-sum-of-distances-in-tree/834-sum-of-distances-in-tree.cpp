class Solution {
public:
    unordered_map<int,int> cnt;
    
    int count(int node, int par, vector<vector<int> >&adj){
        int cur=1; // for the
        for(auto child: adj[node]){
            if(child==par)continue;
            cur+=count(child,node,adj);
        }
        cnt[node]=cur;
        return cur;
    }
    
    int ans0(int node , int par, vector<vector<int> >&adj){
        int ans=cnt[node]-1;
        for(auto child: adj[node]){
            if(child==par)continue;
            ans+=ans0(child,node,adj);
        }
        return ans;
    }
    
    void recur(int node, int par, vector<int>& ans, int n, vector<vector<int> >&adj){
        for(auto child: adj[node]){
            if(child==par)continue;
            ans[child]=ans[node]+n-2*cnt[child];
            recur(child,node,ans,n, adj);
        }
        
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int> >adj(n+1);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        count(0,-1,adj);
        vector<int> ans(n,-1);
        ans[0]=ans0(0,-1, adj);
        recur(0,-1,ans,n,adj);
        return ans;
    }
};