#define ll long long

class Solution {
public:
    // ll min(ll a, ll b){
    //     if(a>b)return b;
    //     return a;
    // }
    
    // ll n;
    ll recur(ll ind, ll k, vector<ll >&dp, vector<int>& nums, int n){
        if(ind<0)return 0;
        if(dp[ind]!=-1)return dp[ind];
        vector<int> v(n,0);
        ll ans=1e18;
        ll cnt=0;
        for(int i=ind;i>=0;i--){
            v[nums[i]]++;
            if(v[nums[i]]==2)cnt+=2;
            else if(v[nums[i]]>2)cnt++;
            ans=min(1ll*ans, 1ll*k+cnt+1ll*recur(i-1,k,dp,nums,n));
        }
        return dp[ind]=ans;
    }
    
    int minCost(vector<int>& nums, int k) {
        
        int n=nums.size();
        vector<ll >dp(n, -1);
        // recur(n-1,k,dp,nums);
        
        ll ans=1e18;
        return recur(n-1,k,dp,nums,n);
    }
};