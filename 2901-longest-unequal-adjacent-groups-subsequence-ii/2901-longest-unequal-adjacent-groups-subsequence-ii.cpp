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

//constants

const long long int inf = 1e18;
const int mod = 1000000007;
#define pi 3.141592653589793238462


class Solution {
public:
    vector<int> g;
    vector<string> w;
    bool check(int i, int j){
        string a=w[i];
        string b=w[j];
        if(a.size()!=b.size())return false;
        if(g[i]==g[j])return false;
        int d=0;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i])d++;
        }
        if(d==1)return true;
        return false;
    }
    
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        vector<int> v(n,-1);
        vector<int> ans(n,1);
        g=groups;
        w=words;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(check(i,j)){
                    if(1+ans[j]>ans[i]){
                        ans[i]=1+ans[j];
                        v[i]=j;
                    }
                }
            }
        }
        int ma=maxv(ans);
        int ind=0;
        for(int i=0;i<n;i++){
            if(ans[i]==ma){
                ind=i;
            }
        }
        
        vector<string> fans;
        while(ind!=-1){
            fans.pb(words[ind]);
            ind=v[ind];
        }
        reverse(fans.begin(), fans.end());
        return fans;
    }
};