class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        map<int,int> mp;
        
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        
        int n=moveFrom.size();
        for(int i=0;i<n;i++){
            int val=mp[moveFrom[i]];
            mp[moveTo[i]]+=val;
            mp[moveFrom[i]]-=val;
        }
        
        vector<int> ans;
        
        for(auto ele: mp){
            if(ele.second>0)ans.push_back(ele.first);
        }
        
        return ans;
    }
};