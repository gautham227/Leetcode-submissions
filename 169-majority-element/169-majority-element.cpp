class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        int ans=INT_MIN;
        int x;
        for(auto val:m){
            if (val.second>ans){
                ans=val.second;
                x=val.first;
            }
        }
        return x;
        
    }
};