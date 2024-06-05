class DSU{
    vector<int> par;
    vector<int> size;
    public:
    DSU(int n){
        for(int i=0;i<=n;i++){
            par.push_back(i);
        }
        size.assign(n+1,1);
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
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        DSU d(n);
        
        for( auto ele: edges ){
            d.Union(ele[0], ele[1]);
        }
        
        vector<int> ans1(n, (1<<30)-1);
        
        for( auto ele: edges ){
            ans1[d.find(ele[0])]&=ele[2];
        }
        
        vector<int> ans;
        for(auto ele: query){
            if(d.find(ele[0])==d.find(ele[1])){
                ans.push_back(ans1[d.find(ele[0])]);
            }
            else{
                ans.push_back(-1);
            }
        }
        
        return ans;
    }
};