// shortforms

#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define all(x) (x).begin(),(x).end()
#define srt(v) sort(v.begin(),v.end())
#define cpy(v2,v1) v2.assign(v1.begin(),v1.end())
#define maxv(a) *max_element(a.begin(), a.end())
#define minv(a) *min_element(a.begin(), a.end())
#define ff first
#define ss second

//type definitions

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

//constants

const long long int inf = 1e18;
const int mod = 1000000007;
#define pi 3.141592653589793238462

class Solution {
public:
    
    int maxSubArray(vector<int>& nums) {
        // based on kadens algo
        int mx=INT_MIN;
        int cs=0;
        for (int i=0;i<nums.size();i++){
            if (cs<0){
                cs=0;
            }
            cs=cs+nums[i];
            mx=max(mx,cs);
        }
        return mx;
    }
};