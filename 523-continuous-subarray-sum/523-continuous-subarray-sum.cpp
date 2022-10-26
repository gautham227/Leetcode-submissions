class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> s;
        int su=0;
        s[su]=0;
        for(int i=0;i<nums.size();i++){
            su+=nums[i];
            su%=k;
            if(s.find(su)!=s.end() && s[su]!=i)return true;
            if(s.find(su)==s.end())s[su]=i+1;
        }
        return false;
    }
};