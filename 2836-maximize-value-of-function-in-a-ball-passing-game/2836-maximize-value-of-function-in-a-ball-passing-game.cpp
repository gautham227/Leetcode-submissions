typedef long long ll;

class binarylifting{
private:
    ll n, mlog;
    vector<vector<int> >par;
    vector<vector<long long> > psum;
public:
    binarylifting(long long no, vector<vector<int> >&adj){
        this->n=no;
        par.resize(n);
        psum.resize(n);
        mlog=38;
        for(long long i=0;i<n;i++){
            par[i].resize(mlog);
            psum[i].resize(mlog);
            for(long long j=0;j<mlog;j++){
                par[i][j]=-1; // parent not assigned yet
                psum[i][j]=0;
            }
        }
        filltable(adj);
    }

    void filltable(vector<vector<int> >&adj){
        vector<bool> vis(n, false);
        for(long long i=0;i<n;i++){
            par[i][0]=adj[i][0];
            psum[i][0]=adj[i][0];
        }
        long long mid;
        for(long long i=1;i<mlog;i++){
            for(long long j=0;j<n;j++){
                mid=par[j][i-1];
                if(mid==-1)continue;
                par[j][i]=par[mid][i-1];
                psum[j][i]=psum[j][i-1]+psum[mid][i-1];
            }
        }
    }

    long long kthpar(long long node, long long k){
        long long ans=node;
        for(long long i=0;i<mlog;i++){
            if((k>>i)&1){
                if(node==-1)return -1;
                ans+=psum[node][i];
                node=par[node][i];
            }
        }
        return ans;
    }
};

class Solution {
public:
    long long getMaxFunctionValue(vector<int>& receiver, long long k) {
        ll n=receiver.size();
        vector<vector<int> >adj(n);
        for(int i=0;i<receiver.size();i++){
            adj[i].push_back(receiver[i]);
        }
        binarylifting* bf = new binarylifting(n,adj);
        long long ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans, bf->kthpar(i, k));
        }
        return ans;
    }
};