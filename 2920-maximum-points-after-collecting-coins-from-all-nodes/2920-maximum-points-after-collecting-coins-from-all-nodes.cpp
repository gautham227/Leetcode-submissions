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

//constants

const long long int inf = 1e18;
const int mod = 1000000007;
#define pi 3.141592653589793238462

class Solution {
public:
    int dp[100001][16];
    ll dfs(int ind, int type2, int par, vector<vector<int> >& adj, vector<int>& coins, int k){
        if(type2>15)return 0;
        if(dp[ind][type2]!=-1)return dp[ind][type2];
        ll c1=coins[ind];
        for(int i=0;i<type2;i++){
            c1/=2;
        }
        ll t1=c1-k;
        ll t2=c1/2;
        for(auto ch: adj[ind]){
            if(ch==par)continue;
            t1+=dfs(ch,type2,ind,adj,coins,k);
            t2+=dfs(ch, type2+1, ind, adj, coins, k);
        }
        
        return dp[ind][type2]=max(t1,t2);
        
    }
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        int n=edges.size()+1;
        memset(dp, -1, sizeof(dp));
        vector<vector<int> >adj(n);
        for(int i=0;i<n-1;i++){
            adj[edges[i][0]].pb(edges[i][1]);
            adj[edges[i][1]].pb(edges[i][0]);
        }
        return dfs(0,0,-1,adj,coins,k);
    }
};