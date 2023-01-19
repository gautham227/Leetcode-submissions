#define ll long long

class Solution {
public:
    
    ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
    
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans=0;
        vector<int> cnt(k,0);
        cnt[0]++;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum=mod_add(sum,nums[i],k);
            cnt[sum]++;
        }
        for(auto val: cnt){
            ans+=(val*(val-1))/2;
        }
        return ans;
    }
};