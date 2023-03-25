class DSU{
    public:
    vector<int> par;
    vector<int> size;
    DSU(int n){
        for(int i=0;i<n;i++){
            par.push_back(i);
        }
        size.assign(n,1);
    }

    int find(int x){
        if(par[x]==x)return x;
        return par[x]=find(par[x]);
    }

    void Union(int u, int v){
        int pu=find(u);
        int pv=find(v);
        if(pu==pv)return;

        if(size[pu]>size[pv]){
            par[pv]=pu;
            size[pu]+=size[pv];
        }
        else{
            par[pu]=pv;
            size[pv]+=size[pu];
        }
        return;
    }
};

class Solution {
public:
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        DSU d(n);
        for(int i=0;i<edges.size();i++){
            d.Union(edges[i][0], edges[i][1]);
        }
        vector<long long> cnt(n,0);
        for(int i=0;i<d.par.size();i++){
            // cout<<d.par[i]<<endl;
            cnt[d.find(i)]++;
        }
        // for(int i=0;i<cnt.size();i++){
        //     cout<<cnt[i]<<" ";
        // }
        // cout<<endl;
        long long ans=0;
        // cout<<ans<<endl;
        for(int i=0;i<cnt.size();i++){
            ans+=cnt[i]*1ll*(n-cnt[i]);
        }
        return ans/2;
    }
};