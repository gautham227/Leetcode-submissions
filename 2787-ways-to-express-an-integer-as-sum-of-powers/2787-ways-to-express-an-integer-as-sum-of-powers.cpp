typedef long long ll;

ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}

class Solution {
public:
    
    int mod=1000000000+7;
    
    long long recur(long long n, ll last, int x, vector<vector<long long> > & dp){
        if(n==0)return 1;        
        if(last==0)return 0;
        // if(n==1)return 1;
        if(dp[n][last]!=-1)return dp[n][last];
        
        long long cur=0;
        
        for(int i=1;i<=last;i++){
            
            ll x1=i;
            for(int j=1;j<x;j++){
                x1*=i;
            }
            
            if(x1>n)break;
            
            cur=mod_add(cur, recur(n-x1,i-1, x,dp), 1ll*mod);
        }
        
        return dp[n][last]=cur;
    }
    
    
    int numberOfWays(int n, int x) {
        vector<vector<long long> > dp(n+1,vector<ll> (n+1, -1));
        return recur(n,n, x, dp);
    }
};