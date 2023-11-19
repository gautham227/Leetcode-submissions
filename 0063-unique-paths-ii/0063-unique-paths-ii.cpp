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
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<ll> prev(n+1,0), cur(n+1,0);
        for(int i=n-1;i>=0;i--){
            if(grid[m-1][i]==1){
                break;
            }
            prev[i]=1;
        }
        // debug(prev)
        for(int i=m-2;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(grid[i][j]==1){
                    cur[j]=0;
                }
                else cur[j]=cur[j+1]+prev[j];
            }
            prev=cur;
            // debug(prev)
            fill(all(cur), 0);
        }
        return prev[0];

    }
};