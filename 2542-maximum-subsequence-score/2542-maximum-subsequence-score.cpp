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
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int> >v;
        int n=nums1.size();
        for(int i=0;i<n;i++){
            v.push_back({nums2[i], nums1[i]});
        }
        srt(v);
        rev(v);
        ll ans=0;
        ll su=0;
        priority_queue<int> pq;
        for(int i=0;i<=k-1;i++){
            su+=v[i][1];
            pq.push(-1*v[i][1]);
        }
        ans=su*v[k-1][0];
        for(int i=k;i<n;i++){
            su+=v[i][1];
            pq.push(-1*v[i][1]);
            su+=pq.top();
            pq.pop();
            ans=max(ans, (su)*v[i][0]);
        }
        return ans;
    }
};