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

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int > >v;
        int n=scores.size();
        for(int i=0;i<n;i++){
            v.push_back({ages[i], scores[i]});
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        int ans=0;
        
        vector<int> dp(n, 0);
        
        for(int i=0;i<n;i++){
            int mi=v[i].ss;
            dp[i]=mi;
            int cur=mi;
            for(int j=0;j<i;j++){
                if(v[j].ss>=mi){
                    dp[i]=max(dp[j]+cur, dp[i]);
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};