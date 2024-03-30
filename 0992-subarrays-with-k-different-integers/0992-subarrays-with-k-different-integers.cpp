class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        map<int, int> cntr, last;
        set<int> s;
        int ans=0;
        int st=0, en=0;
        int n=nums.size();
        for(en=0;en<n;en++){
            cntr[nums[en]]++;
            if(cntr[nums[en]]==1){
                last[nums[en]]=en;
                s.insert(en);
            }
            else{
                s.erase(s.find(last[nums[en]]));
                s.insert(en);
                last[nums[en]]=en;
            }
            while(cntr.size()>k){
                cntr[nums[st]]--;
                if(cntr[nums[st]]==0){
                    cntr.erase(cntr.find(nums[st]));
                    last.erase(last.find(nums[st]));
                    s.erase(s.find(st));
                }
                st++;
            }
            if(cntr.size()==k)ans+=(*s.begin())-st+1;
        }
        return ans;
    }
};