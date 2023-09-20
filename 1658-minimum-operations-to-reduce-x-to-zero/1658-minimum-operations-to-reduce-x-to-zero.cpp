class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        vector<int> presum;
        int sum=0;
        presum.push_back(0);
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            presum.push_back(sum);
        }
        int mlen=-1;
        int val;
        int diff=presum[presum.size()-1]-x;
        for(int i=0;i<presum.size();i++){
            val=presum[i]-diff;
            if(val>=0){
                auto it=lower_bound(presum.begin(),presum.end(),val);
                if(it!=presum.end() && *it==val){
                    mlen=max(mlen,i-(int)(it-presum.begin()));
                }
            }
        }
        if(mlen==-1)return mlen;
        return nums.size()-mlen;
    }
};