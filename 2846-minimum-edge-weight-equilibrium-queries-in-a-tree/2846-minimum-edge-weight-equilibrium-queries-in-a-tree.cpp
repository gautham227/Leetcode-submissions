typedef long long ll;

class LCA_binarylifting{
private:
    ll n, mlog;
    vector<vector<int> >par;
    vector<int> level;

public:
    LCA_binarylifting(int no, vector<vector<int> >&adj, int root){
        this->n=no;
        par.resize(n);
        mlog=log2(no)+2;
        level.resize(n);
        for(int i=0;i<n;i++){
            par[i].resize(mlog);
            for(int j=0;j<mlog;j++){
                par[i][j]=-1; // parent not assigned yet
            }
        }
        filltable(root, adj);
    }

    void pardfs(int node, vector<vector<int> >& adj, vector<bool> & vis, int l){
        vis[node]=true;
        level[node]=l;
        for(auto child: adj[node]){
            if(!vis[child]){
                par[child][0]=node;
                pardfs(child, adj,vis, l+1);
            }
        }
    }

    void filltable(int root, vector<vector<int> >&adj){
        vector<bool> vis(n, false);
        pardfs(root, adj, vis, 0);
        int mid;
        for(int i=1;i<mlog;i++){
            for(int j=0;j<n;j++){
                mid=par[j][i-1];
                if(mid==-1)continue;
                par[j][i]=par[mid][i-1];
            }
        }
    }

    int kthpar(int node, int k){
        for(int i=0;i<mlog;i++){
            if((k>>i)&1){
                if(node==-1)return -1;
                node=par[node][i];
            }
        }
        return node;
    }

    int lca(int a, int b){
        if(level[a]>level[b]){
            swap(a,b);
        }
        int diff=level[b]-level[a];
        b=kthpar(b,diff);

        if(a==b)return a;
        for(int i=mlog-1;i>=0;i--){
            int par1=par[a][i];
            int par2=par[b][i];
            if(par1!=par2 && par1!=-1 && par2!=-1){
                a=par1;
                b=par2;
            }
        }
        return par[a][0];
    }
};

class Solution {
public:
    unordered_map<int, vector<int> > diffedges; 
    void dfs(int node, int par, vector<vector<vector<int> > >& adj, vector<int>& arr){
        for(int i=0;i<adj[node].size();i++){
            if(adj[node][i][0]==par)continue;
            arr[adj[node][i][1]]++;
            dfs(adj[node][i][0], node, adj, arr);
            arr[adj[node][i][1]]--;
        }
        diffedges[node]=arr;
    }
    
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& q) {
        vector<vector<int> >adj(n);
        vector<vector<vector<int> > >adj1(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            adj1[edges[i][1]].push_back({edges[i][0], edges[i][2]});
            adj1[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
        LCA_binarylifting lcafinder(n,adj,0);
        vector<int> v(27,0);
        vector<int> ans;
        dfs(0,-1,adj1,v);
        for(int i=0;i<q.size();i++){
            int lca=lcafinder.lca(q[i][0], q[i][1]);
            int ma=0, tot=0;
            for(int j=1;j<=26;j++){
                tot+=diffedges[q[i][0]][j]+diffedges[q[i][1]][j]-2*diffedges[lca][j];
                ma=max(ma,diffedges[q[i][0]][j]+diffedges[q[i][1]][j]-2*diffedges[lca][j]);
            }
            ans.push_back(tot-ma);
        }
        return ans;
    }
};