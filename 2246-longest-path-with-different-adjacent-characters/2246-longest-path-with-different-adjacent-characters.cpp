class Solution {
public:
    int ans=0;
    
    int dfs(vector<vector<int> >&adj, string &s, int node){
        int l1=0, l2=0; // size of 2 largest nodes
        int cur;
        for(auto x: adj[node]){
            cur=dfs(adj, s,x);
            ans=max(ans,cur);
            if(s[x]!=s[node]){
                if(l2<cur){
                    l2=cur;
                    if(l2>l1){
                        swap(l1,l2);
                    }
                }
            }
        }
        int ma=l1+l2+1;
        ans=max(ans,ma);
        return l1+1;
    }
    
    int longestPath(vector<int>& parent, string s) {
        vector<vector<int> >adj(s.size());
        for(int i=1;i<s.size();i++){
            adj[parent[i]].push_back(i);
        }
        dfs(adj,s,0);
        return ans;
    }
};