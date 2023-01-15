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
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n=vals.size();
        vector<vector<int> >adj(n);
        
        for(auto ele: edges){
            adj[ele[0]].push_back(ele[1]);
            adj[ele[1]].push_back(ele[0]);
        }
        
        DSU d(n);
        
        int ans=0;
        
        vector<vector<int> > nodes;
        for(int i=0;i<n;i++){
            nodes.push_back({vals[i], i});
        }
        
        sort(nodes.begin(), nodes.end());
        
        map<int,vector<int > >mp1;
        
        for(int i=0;i<n;i++){
            mp1[vals[i]].push_back(i);
        }
        for(auto &ele: mp1){
            for(auto ele1: ele.second){
                for(auto ed: adj[ele1]){
                    if(vals[ele1]>=vals[ed]){
                        d.Union(ele1, ed);
                    }
                }
            }
            
            map<int,int> cur;
            
            for(auto ele1: ele.second){
                cur[d.find(ele1)]++;
            }
            
            for(auto ele1: cur){
                ans+=ele1.second*(ele1.second-1)/2;
            }
            
        }
        
        return ans+n;
    }
};