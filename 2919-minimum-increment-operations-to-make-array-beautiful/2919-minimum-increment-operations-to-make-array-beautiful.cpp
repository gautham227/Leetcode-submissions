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
    long long minIncrementOperations(vector<int>& nums, int k) {
        ll n=nums.size();
        ll dp[n+1][2];
        memset(dp, 0, sizeof(dp));
        dp[0][0]=0;
        dp[0][1]=max(0,k-nums[0]);
        dp[1][0]=0;
        dp[1][1]=max(0,k-nums[1]);
        dp[2][0]=min(dp[0][1], dp[1][1]);
        dp[2][1]=max(0,k-nums[2]);
        for(int i=3;i<n;i++){
            ll prevma=1e18;
            int cnt=0;
            for(int j=i-1; j>=0 && cnt<2 ; j--){
                prevma=min(prevma, dp[j][1]);
                cnt++;
            }
            dp[i][0]=prevma;
            dp[i][1]=max(0,k-nums[i]);
            cnt=0;
            ll val1=1e18;
            for(int j=i-1;j>=0 && cnt<3 ; j--){
                cnt++;
                val1=min(val1,dp[j][1]);
            }
            dp[i][1]+=val1;
        }
        return min(dp[n-1][0], dp[n-1][1]);
    }
};