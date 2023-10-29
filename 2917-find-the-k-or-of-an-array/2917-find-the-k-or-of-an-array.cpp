class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        map<int,int> mp;
        for(auto ele: nums){
            int cur=ele;
            int ind=0;
            while(cur>0){
                if(cur%2==1){
                    mp[ind]++;
                }
                ind++;
                cur/=2;
            }
        }
        int ans=0;
        for(auto ele: mp){
            if(ele.second>=k)ans|=(1<<ele.first);
        }
        return ans;
    }
};