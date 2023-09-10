typedef long long ll;

ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}

class Solution {
public:
    
    ll mod=1000000000+7;
    
    ll recur(ll ind, ll used, ll n, vector<vector<ll> >& dp){
        if(ind>=2*n)return 1;
        if(dp[ind][used]!=-1)return dp[ind][used];
        ll ans=0;
        if(used>0){
            ans=mod_mul(used, recur(ind+1,used-1,n,dp),mod);
        }
        ll to_be_taken=n-used-(ind-used)/2;
        ans=mod_add(ans,mod_mul(to_be_taken, recur(ind+1,used+1,n,dp),mod), mod);
        return dp[ind][used]=ans;
    }
    
    int countOrders(int n) {
        vector<vector<ll> >dp(2*n+1, vector<ll>(2*n+1,-1));
        return recur(0,0,n,dp);
    }
};