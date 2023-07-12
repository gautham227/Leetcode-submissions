class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        vector<int> arr;
        for(int i=1;i<nums.size();i++){
            arr.push_back(nums[i]-nums[i-1]);
        }
        
        int ans=0;
        
        int cnt=0;
        
        for(int i=0;i<arr.size();i++){
            if(cnt>0 && arr[i]==arr[i-1]*-1)cnt++;
            else if(arr[i]==1)cnt=1;
            else cnt=0;
            ans=max(ans,cnt);
        }
        
        
        if(ans==0)return -1;
        return ans+1;
        
    }
};