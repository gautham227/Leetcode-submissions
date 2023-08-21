class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        map<int,vector<int> > mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        int ans=1;
        
        for(auto &ele: mp){
            int ind=1;
            int ind1=0;
            vector<int> x = ele.second;
            while(ind<x.size()){
                while(x[ind]-x[ind1]-(ind-ind1)>k){
                    ind1++;
                }
                ans=max(ans,ind-ind1+1);
                ind++;
            }
        }        
        
        return ans;
    }
};