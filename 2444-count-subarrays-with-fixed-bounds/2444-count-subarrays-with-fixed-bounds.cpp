class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans=0;
        int last=-1;
        long long lastmini=-1;
        long long lastmaxi=-1;
        long long ind=0;
        for(auto ele: nums){
            if(ele>=minK && ele<=maxK){
                if(ele==minK)lastmini=ind;
                if(ele==maxK)lastmaxi=ind;
                ans+=max(0*1ll,-last+min(lastmaxi,lastmini));
            }
            else{
                last=ind;
                ans+=max(0*1ll,-last+min(lastmaxi,lastmini));
            }
            ind++;
        }
        return ans;
    }
};