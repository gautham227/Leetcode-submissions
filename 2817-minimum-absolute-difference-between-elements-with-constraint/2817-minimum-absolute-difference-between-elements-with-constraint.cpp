class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        set<int> s;
        int n=nums.size();
        int ind=n-1;
        int st=ind-x;
        int ans=INT_MAX;
        while(st!=-1){
            
            s.insert(nums[ind]);
            auto it=s.lower_bound(nums[st]);
            
            if(it!=s.end()){
                ans=min(ans, abs(nums[st]-(*it)));
            }
            if(it!=s.begin()){
                it--;
                ans=min(ans, abs(nums[st]-(*it)));
            }
            st--;
            ind--;
        }
        return ans;
    }
};