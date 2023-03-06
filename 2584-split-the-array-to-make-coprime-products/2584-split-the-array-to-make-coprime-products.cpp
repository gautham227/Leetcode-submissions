// Created by: G Gautham Krishna

// shortforms

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
    
    void primeFactors(int n,unordered_map<ll,ll>&mp)
    {
        while (n % 2 == 0){
            mp[2]++;
            n = n/2;
        }
        for (int i = 3; i <= sqrt(n); i = i + 2)
        {
            while (n % i == 0)
            {
                mp[i]++;
                n = n/i;
            }
        }

        if (n > 2){
            mp[n]++;
        }
    }
    
    void pf1(int n, unordered_set<ll>& s, unordered_map<ll,ll>&mp, ll &cnt){
        int c;
        while (n % 2 == 0){
            c=2;
            if(s.find(c)==s.end()){
                s.insert(c);
                cnt+=mp[c]-1;
            }
            else{
                cnt--;
            }
            n = n/2;
        }
        for (int i = 3; i <= sqrt(n); i = i + 2)
        {
            while (n % i == 0)
            {
                c=i;
                if(s.find(c)==s.end()){
                    s.insert(c);
                    cnt+=mp[c]-1;
                }
                else{
                    cnt--;
                }
                n = n/i;
            }
        }

        if (n > 2){
            c=n;
            if(s.find(c)==s.end()){
                s.insert(c);
                cnt+=mp[c]-1;
            }
            else{
                cnt--;
            }
        }
    }
    
    int findValidSplit(vector<int>& nums) {
        unordered_map<ll,ll> mp;
        for(auto ele: nums)primeFactors(ele, mp);
        int n=nums.size();
        unordered_set<ll> s;
        ll cnt=0;
        for(int i=0;i<n;i++){
            pf1(nums[i],s,mp,cnt);
            if(cnt==0  && i!=n-1)return i;
        }
        return -1;
    }
};