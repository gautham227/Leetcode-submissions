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

    
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        map<vector<int>, set<int> > mp;
        
        for(auto ele: edges){
            mp[{min(ele[1],ele[2]), max(ele[1],ele[2])}].insert(ele[0]);
        }

        vector<vector<int> >edges1;
        
        vector<vector<int> > edges2, edges3;
        
        for(auto ele: mp){
            if(ele.second.find(3)!=ele.second.end()){
                edges1.push_back({1,ele.first[0],ele.first[1]});
            }
            else{
                if(ele.second.find(1)!=ele.second.end()){
                    edges2.push_back({1,ele.first[0],ele.first[1]});
                }
                if(ele.second.find(2)!=ele.second.end()){
                    edges3.push_back({1,ele.first[0],ele.first[1]});
                }
            }
        }
        
        sort(edges1.begin(), edges1.end());
        sort(edges2.begin(), edges2.end());
        sort(edges3.begin(), edges3.end());
        DSU d(n+1), d1(n+1);
        
        int ans=0;
        for(auto ele: edges1){
            if(d.find(ele[1])!=d.find(ele[2])){
                ans+=ele[0];
                d.Union(ele[1],ele[2]);
                d1.Union(ele[1],ele[2]);
            }
        }
        
        for(auto ele: edges2){
            if(d.find(ele[1])!=d.find(ele[2])){
                ans+=ele[0];
                d.Union(ele[1],ele[2]);
            }
        }
        
        for(auto ele: edges3){
            if(d1.find(ele[1])!=d1.find(ele[2])){
                ans+=ele[0];
                d1.Union(ele[1],ele[2]);
            }
        }
        
        
        bool flag=true;
        for(int i=1;i<=n;i++){
            if(d.find(i)!=d.find(1))flag=false;
            if(d1.find(i)!=d1.find(1))flag=false;
        }
        
        if(!flag)return -1;
        return edges.size()-ans;
    }
};