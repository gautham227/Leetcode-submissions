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
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        vector<int> prev(1001,-1000002), cur(1001,-1000002);
        prev[0]=0;
        for(int i=1;i<=n;i++){
            int ind=i-1;
            for(int j=0;j<=target;j++){
                if(nums[ind]>j){
                    cur[j]=prev[j];
                }
                else{
                    cur[j]=prev[j];
                    cur[j]=max(cur[j], 1+prev[j-nums[ind]]);
                }
            }
            prev=cur;
            for(int j=0;j<cur.size();j++){
                cur[i]=-1000002;
            }
        }
        if(prev[target]<=0)return -1;
        return prev[target];
    }
};