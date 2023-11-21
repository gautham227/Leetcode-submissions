const int mod = 1000000000+7;

class Solution {
public:
    int revnums(int num){
        int cur=0;
        while(num>0){
            cur*=10;
            cur+=num%10;
            num/=10;
        }
        return cur;
    }
    int countNicePairs(vector<int>& nums) {
        long long ans=0;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]-revnums(nums[i])]++;
        }
        for(auto ele: mp){
            ans+=(1ll*ele.second * 1ll*(ele.second -1))/2;
            ans%=mod;
        }
        
        return ans;
    }
};