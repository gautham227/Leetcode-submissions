class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        long long sum=accumulate(nums.begin(), nums.end(), 0*1ll);
        if(sum<target)return -1;
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        multiset<int> ms;
        for(int i=0;i<nums.size();i++){
            ms.insert(nums[i]);
        }
        vector<int> flags(32, false);
        int ind=0;
        int target1=target;
        while(target1>0){
            if(target1%2==1){
                flags[ind]=true;
            }
            target1/=2;
            ind++;
        }
        int ans=0;
        sum=0;
        for(int i=0;i<flags.size();i++){
            if(flags[i]){
                while(ms.size()>0 && (*ms.begin())<=(1ll*(1<<i))){
                    sum+=*ms.begin();
                    ms.erase(ms.begin());
                }
                if(sum>=(1ll*(1<<i))){
                    sum-=(1ll*(1<<i));
                }
                else{
                    int val = (*ms.begin());
                    // cout<<val<<endl;
                    // cout<<i<<endl;
                    ms.erase(ms.begin());
                    ms.insert(val/2);
                    ms.insert(val/2);
                    i--;
                    ans++;
                }
                
            }
        }
        return ans;
    }
};