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

//constants

const long long int inf = 1e18;
const int mod = 1000000007;
#define pi 3.141592653589793238462

ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}

class Solution {
public:
    
    int n,m;
    
    long long recur(int x, int y, vector<vector<int> > &grid, vector<vector<ll> >&dp){
        if(x>=n || y>=m || x<0 || y<0)return 0;
        if(dp[x][y]!=-1)return dp[x][y];
        ll a=0, b=0, c=0, d=0;
        if(x-1>=0 && grid[x-1][y]>grid[x][y])a=recur(x-1,y,grid,dp);
        if(y-1>=0 && grid[x][y-1]>grid[x][y])b=recur(x,y-1,grid,dp);
        if(x+1<n && grid[x+1][y]>grid[x][y])c=recur(x+1,y,grid,dp);
        if(y+1<m && grid[x][y+1]>grid[x][y])d=recur(x,y+1,grid,dp);
        return dp[x][y]=(1+a+b+c+d)%mod;
    }
    
    int countPaths(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<long long> >dp(n, vector<ll>(m,-1));
        long long ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=mod_add(ans,recur(i,j,grid,dp),mod);
            }
        }
        return ans;
    }
};