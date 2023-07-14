typedef long long ll;
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}

class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        long long ans=1;
        bool flag=false;
        int count=1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(!flag && nums[i]==1)flag=true;
            if(flag && nums[i]==0)count++;
            else {
                ans=mod_mul(ans,count,1000000000+7);
                count=1;
            }
        }
        if(!flag)return 0;
        return ans;
    }
};