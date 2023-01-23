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

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        ll l=length;
        ll w=width;
        ll h=height;
        ll m=mass;
        bool flag1=false;
        bool flag2=false;
        if(l>=10000 || w>=10000 || h>=10000 || l*h*w>=1000000000)flag1=true;
        if(m>=100)flag2=true;
        if(flag1 && flag2)return "Both";
        else if(flag1 && !flag2)return "Bulky";
        else if(!flag1 && flag2)return "Heavy";
        return "Neither";
        
    }
};