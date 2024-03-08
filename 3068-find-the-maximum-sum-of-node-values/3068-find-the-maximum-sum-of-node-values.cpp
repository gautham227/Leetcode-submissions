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
    
    ll recur(ll ind, ll par, ll type, vector<vector<int> >& adj, vector<vector<ll> >& dp, ll k, vector<ll>& nums){
        if(dp[ind][type]!=-1)return dp[ind][type];
        vector<ll> pos, neg;
        ll odd1=0, even1=0;
        if(type==1){
            odd1=nums[ind];
            even1=nums[ind]^k;
        }
        else{
            even1=nums[ind];
            odd1=nums[ind]^k;
        }
        ll odd=odd1;
        ll even=even1;
        // cout<<"odd "<<odd<<endl;
        // cout<<"even "<<even<<endl;
        for(auto ele: adj[ind]){
            if(ele==par)continue;
            pos.push_back(recur(ele,ind,1,adj,dp,k,nums));
            neg.push_back(recur(ele,ind,0,adj,dp,k,nums));                         
        }
        // for(int i=0;i<pos.size();i++){
        //     cout<<pos[i]<<" "<<neg[i]<<endl;
        // }
        // cout<<endl;
        if(pos.size()==0){
            if(type==0)return dp[ind][type]=nums[ind];
            return dp[ind][type]=nums[ind]^k;
        }
        ll ans1=accumulate(pos.begin(), pos.end(), 0*1ll);
        if(pos.size()%2==0)even=max(even, even+ans1);
        else odd=max(odd,odd+ans1);
        // cout<<"oediff "<<odd<<" "<<even<<endl;
        vector<ll> pe;
        for(ll i=0;i<pos.size();i++){
            pe.push_back(neg[i]-pos[i]);
        }
        sort(pe.begin(), pe.end());
        for(ll i=0;i<pe.size();i++){
            ans1+=pe[i];
            if((pos.size()-i-1)%2==1){
                odd=max(odd,odd1+ans1);
            }
            else{
                even=max(even,even1+ans1);
            }
        }
        ans1=accumulate(pos.begin(), pos.end(), 0*1ll);
        reverse(pe.begin(), pe.end());
        for(ll i=0;i<pe.size();i++){
            ans1+=pe[i];
            if((pos.size()-i-1)%2==1){
                odd=max(odd,odd1+ans1);
            }
            else{
                even=max(even,even1+ans1);
            }
        }
        return dp[ind][type]=max(odd,even);
    }
    
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        ll n=nums.size();
        vector<vector<int> >adj(n);
        for(ll i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<vector<ll> > dp(n, vll(2,-1));
        vector<ll> nums1;
        for(ll ele: nums)nums1.push_back(ele);
        ll ans = recur(0,-1,0,adj,dp,k,nums1);
        // for(int i=0;i<2;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<i<<" "<<j<<" "<<dp[j][i]<<endl;
        //     }
        //     cout<<endl;
        // }
        return ans;
    }
};