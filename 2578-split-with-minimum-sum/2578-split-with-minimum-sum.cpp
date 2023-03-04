// Created by: G Gautham Krishna

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
    int splitNum(int num) {
        vector<int> v;
        int num1=num;
        while(num1>0){
            v.pb(num1%10);
            num1/=10;
        }
        srt(v);
        rev(v);
        int ans=0;
        int n=v.size();
        for(int i=0;i<n;i++){
            int cur=v[i];
            for(int j=0;j<i/2;j++){
                cur*=10;
            }
            ans+=cur;
        }
        return ans;
    }
};