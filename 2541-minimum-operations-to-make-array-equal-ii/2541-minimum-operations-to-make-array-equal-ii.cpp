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
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        ll su1=0, su2=0;
        if(nums1==nums2)return 0;
        if(k==0)return -1;
        for(auto ele: nums1)su1+=ele;
        for(auto ele: nums2)su2+=ele;
        if(su1!=su2)return -1;
        ll n=nums1.size();
        ll ans=0;
        for(int i=0;i<n;i++){
            if(abs(nums1[i]-nums2[i])%k!=0)return -1; 
            else ans+=abs(nums1[i]-nums2[i])/k;
        }
        return ans/2;
    }
};