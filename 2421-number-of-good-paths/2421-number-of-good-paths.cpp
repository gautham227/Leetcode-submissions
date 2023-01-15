class DSU{
    vector<int> par;
    vector<int> size;
    vector<pair<int,int> >mval;
    public:
    DSU(int n, vector<int>& vals){
        for(int i=0;i<=n;i++){
            par.push_back(i);
        }
        size.assign(n+1,1);
        for(int i=0;i<n;i++){
            mval.push_back({vals[i],1});
        }
    }

    int find(int x){
        if(par[x]==x)return x;
        return par[x]=find(par[x]);
    }

    int Union(int u, int v){
        int pu=find(u);
        int pv=find(v);
        if(pu==pv)return 0;

        if(size[pu]>size[pv]){
            par[pv]=pu;
            size[pu]+=size[pv];
            if(mval[pu].first==mval[pv].first){
                mval[pu].second+=mval[pv].second;
                // mval[pv].second+=mval[pu].second;
            }
            else if(mval[pu].first<mval[pv].first){
                mval[pu]=mval[pv];
            }
            return mval[pu].second-1;
        }
        else{
            par[pu]=pv;
            size[pv]+=size[pu];
            if(mval[pu].first==mval[pv].first){
                mval[pv].second+=mval[pu].second;
                // mval[pv].second+=mval[pu].second;
            }
            else if(mval[pv].first<mval[pu].first){
                mval[pv]=mval[pu];
            }
            return mval[pv].second-1;
        }
        return 0;
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
        
        // for(int i=0;i<n;i++){
        //     cout<<i<<"->";
        //     for(auto ele: adj[i]){
        //         cout<<ele<<" ";
        //     }
        //     cout<<endl;
        // }
        
        
        DSU d(n, vals);
        
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
        
        // for(auto ele: nodes) cout<<ele[1]<<" ";
        // cout<<endl;
        for(auto &ele: mp1){
            // ans+=d.Union(nodes[i][1], nodes[i-1][1]);
            // cout<<ans<<endl;
            for(auto ele1: ele.second){
                for(auto ed: adj[ele1]){
                    if(vals[ele1]>=vals[ed]){
                        // cout<<endl;
                        // cout<<ele1<<" "<<ed<<endl;
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
            
            // cout<<ans<<" ";
            
        }
        
        return ans+n;
    }
};