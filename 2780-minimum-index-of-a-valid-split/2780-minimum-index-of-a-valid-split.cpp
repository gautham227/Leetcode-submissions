class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto ele: nums) mp[ele]++;
        int dom=-1;
        int count=0;
        for(auto ele: mp){
            if(ele.second>count){dom=ele.first; count=ele.second;}
        }
        
        int cnt=0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==dom)cnt++;
            
            if(cnt*2>i+1 && (mp[dom]-cnt)*2>nums.size()-i-1)return i;
        }
            
            
        return -1;
        
    }
};