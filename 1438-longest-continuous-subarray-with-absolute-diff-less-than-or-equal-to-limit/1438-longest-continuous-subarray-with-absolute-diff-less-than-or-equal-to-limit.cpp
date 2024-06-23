class Solution {
public:
    
    bool check(int val, multiset<int>& s, int lim){
        if(s.size()==0)return 1;
        auto it1=s.begin();
        auto it2=(--s.end());
        if((abs(val-(*it1))<=lim) && ((abs(val-(*it2))<=lim)))return true;
        return false;
    }
    
    int longestSubarray(vector<int>& nums, int limit) {
        int ans=1;
        multiset<int> s;
        int ind=0;
        for(int i=0;i<nums.size();i++){
            while(check(nums[i], s, limit)==false){
                s.erase(s.find(nums[ind]));
                ind++;
            }
            s.insert(nums[i]);
            ans=max(ans, (int)s.size());
        }
        return ans;
    }
};