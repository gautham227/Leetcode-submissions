class Solution {
public:
    
    long long ans=0;
    
    long long recur(int ind, vector<vector<int> >& adj, int par, int mseat){
        if(adj[ind].size()==1 && adj[ind][0]==par){ans++;return 1;}
        long long cur=0;
        for(auto ele: adj[ind]){
            if(ele==par)continue;
            cur+=recur(ele,adj,ind,mseat);
        }
        if(ind==0)return 0;
        cur++;
        ans+=cur/mseat;
        if(cur%mseat!=0)ans++;
        return cur;
    }
    
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n=roads.size()+1;
        vector<vector<int> >adj(n);
        for(auto ele: roads){
            adj[ele[0]].push_back(ele[1]);
            adj[ele[1]].push_back(ele[0]);
        }
        recur(0,adj,-1,seats);
        return ans;
    }
};