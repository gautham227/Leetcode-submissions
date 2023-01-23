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
    
    bool check(ll val, vector<ll>& cur, ll r, ll k){
        ll n=cur.size();
        vector<ll> ne(n+1,0);
        ll extra=0;
        for(int i=0;i<n;i++){
            extra+=ne[i];
            if(cur[i]+extra>=val)continue;
            else{
                ll need=val-cur[i]-extra;
                if(k<need)return false;
                else{
                    k-=need;
                    extra+=need;
                    ne[min(n,1ll*i+2*r+1)]-=need;
                }
            }
        }
        return true;
    }
    
    
    long long maxPower(vector<int>& stations, int r, int k) {
        long long l=0, h=100000000000000000;
        ll n=stations.size();
        vector<ll> cur(n,0);
        ll val=0;
        ll sub=0;
        for(int i=0;i<n;i++){
            val+=stations[i];
            if(i-r-1>=0)sub+=stations[i-r-1];
            cur[i]+=val-sub;
        }
        val=0;
        sub=0;
        for(int i=n-1;i>=0;i--){
            val+=stations[i];
            if(i+r+1<n)sub+=stations[i+r+1];
            cur[i]+=val-sub;
            
        }
        
        for(int i=0;i<n;i++){
            cur[i]-=stations[i];
        }
        while(h-l>1){
            ll mid=h-(h-l)/2;
            if(check(mid,cur,r,k)){
                l=mid;
            }
            else{
                h=mid-1;
            }
        }
        if(check(h,cur,r,k))return h;
        return l;
        return 0;
    }
};