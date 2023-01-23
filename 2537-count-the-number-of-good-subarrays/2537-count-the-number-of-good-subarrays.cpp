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
    long long countGood(vector<int>& nums, int k) {
        map<ll, ll> mp;
        ll cur=0;
        ll ans=0;
        ll n=nums.size();
        ll last=0;
        for(ll i=0;i<n;i++){
            while(cur>=k && last<i){
                if(cur>=k)ans+=n-i+1;
                mp[nums[last]]--;
                cur-=mp[nums[last]];
                last++;
            }
            cur+=mp[nums[i]];
            mp[nums[i]]++;
            // cout<<ans<<" "<<cur<<endl;
        }
        
        while(cur>=k){
            if(cur>=k)ans+=1;    
            mp[nums[last]]--;
                cur-=mp[nums[last]];
                last++;
            }
        // cout<<endl;
        return ans;
    }
};