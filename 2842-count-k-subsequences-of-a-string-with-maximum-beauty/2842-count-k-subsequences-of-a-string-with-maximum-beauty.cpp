typedef long long ll;

class Solution {
public:
    
    ll mod=1000000000+7;
    
    ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
    ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
    ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
    
        ll ncr(int n, int r)
    {
        ll p = 1, k = 1;
        if (n - r < r)
            r = n - r;
        if (r != 0) {
            while (r) {
                p *= n;
                k *= r;
                long long m = __gcd(p, k);
                p /= m;
                k /= m;
                n--;
                r--;
            }
        }

        else
            p = 1;
        return p;
    }
    
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        map<char, ll> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        if(k>mp.size())return 0;
        ll ans=1;
        vector<ll> v;
        for(auto ele: mp){
            v.push_back(ele.second);
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        
        map<ll,ll> mp1;
        for(auto ele:v){
            mp1[ele]++;
        }
        vector<vector<ll> >v1;
        for(auto ele: mp1){
            v1.push_back({ele.first, ele.second});
        }
        sort(v1.begin(), v1.end());
        reverse(v1.begin(), v1.end());
        int ind=0;
        while(k>0){
            if(v1[ind][1]>=k){
                ans=mod_mul(ans,ncr(v1[ind][1],k), mod);
                while(k>0){
                    ans=mod_mul(ans,v1[ind][0],mod);
                    k--;
                }
                v1[ind][1]=0;
                ind++;
            }
            else{
                ans=mod_mul(ans,v1[ind][0],mod);
                v1[ind][1]--;
                if(v1[ind][1]==0){
                    ind++;
                }
                k--;
            }
        }
        return ans;
    }
};