// Created by: G Gautham Krishna

#define pb push_back

class Solution {
public:
    
    map<vector<int>, int> mp;
    
    int recur(int ind, int par, vector<vector<int> >&adj, set<vector<int> >&g){
        if(mp.find({par,ind})!=mp.end())return mp[{par,ind}];
        int cnt=0;
        for(auto ch: adj[ind]){
            if(ch==par)continue;
            if(g.find({ind,ch})!=g.end())cnt++;
            cnt+=recur(ch,ind,adj,g);
        }
        return mp[{par,ind}]=cnt;
    }
    
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        set<vector<int> >g;
        int n=edges.size()+1;
        vector<vector<int> >adj(n);
        for(int i=0;i<n-1;i++){
            adj[edges[i][0]].pb(edges[i][1]);
            adj[edges[i][1]].pb(edges[i][0]);
        }
        for(auto ele: guesses)g.insert(ele);
        int ans=0;
        for(int i=0;i<n;i++){
            if(recur(i,-1,adj,g)>=k)ans++;
        }
        return ans;
    }
};