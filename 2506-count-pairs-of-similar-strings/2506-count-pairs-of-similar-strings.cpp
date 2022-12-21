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
    int similarPairs(vector<string>& words) {
        map<ll,ll> mp;
        for(int i=0;i<words.size();i++){
            ll ans=0;
            for(int j=0;j<words[i].size();j++){
                ans|=(1<<(words[i][j]-'a'));
            }
            // cout<<ans<<endl;
            mp[ans]++;
        }
        int an=0;
        for(auto ele: mp){
            an+=ele.ss*(ele.ss-1)/2;
        }
        return an;
    }
};