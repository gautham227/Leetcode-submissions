// Created by: G Gautham Krishna

#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define all(x) (x).begin(),(x).end()
#define srt(v) sort(v.begin(),v.end())
#define rev(v) reverse(v.begin(),v.end())
#define lb(v,x) lower_bound(v.begin(),v.end(),x)
#define ub(v,x) upper_bound(v.begin(),v.end(),x)
#define cpy(v2,v1) v2.assign(v1.begin(),v1.end())
#define maxv(a) *max_element(a.begin(), a.end())
#define minv(a) *min_element(a.begin(), a.end())
#define ff first
#define ss second
#define endl "\n"

//type definitions

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

class Solution {
public:
    
    void bfs(int v, unordered_map<int, vector<int> >&mp, vector<ll>& dist, vector<int>& arr){
        vector<bool> vis(50010,false);
        queue<int> q;
        q.push(v);
        vis[v]=1;
        dist[v]=0;
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            for(int child : mp[arr[cur]]){
                if(vis[child]==1){
                    continue;
                }
                q.push(child);
                vis[child]=1;
                dist[child]=dist[cur]+1;
            }
            if(cur!=0){
                ll child=cur-1;
                if(vis[child]==0){
                    q.push(child);
                    vis[child]=1;
                    dist[child]=dist[cur]+1;
                }
            }
            if(cur!=arr.size()-1){
                ll child=cur+1;
                if(vis[child]==0){
                    q.push(child);
                    vis[child]=1;
                    dist[child]=dist[cur]+1;
                }
            }
            mp[arr[cur]]={};
        }
    }
    
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        vector<ll> dist;
        for(int i=0;i<50010;i++){
            dist.push_back(1ll*10000000000000000);
        }
        unordered_map<int, vector<int> > mp;
        for (int i = 0; i < arr.size(); ++i) {
            if (i > 0 && i+1 < arr.size() && arr[i] == arr[i+1] && arr[i] == arr[i-1]) {
                continue;
            }
            mp[arr[i]].push_back(i);
        }
        bfs(0,mp,dist,arr);
        return dist[n-1];
    }
};