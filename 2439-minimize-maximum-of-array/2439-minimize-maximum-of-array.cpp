class Solution {
public:
    
    bool check(long long no, vector<int>& nums){
        long long last=0;
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i]+last>no){
                last=nums[i]+last-no;
            }
            else{
                last=0;
            }
        }
        
        if(1ll*nums[0]+last>no)return false;
        return true;
    }
    
    int minimizeArrayValue(vector<int>& nums) {
        int l,r;
        l=0;
        r=INT_MAX;
        
        while(r-l>1){
            int mid=l+(r-l)/2;
            if(check(mid,nums)){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        
        if(check(l,nums))return l;
        
        return r;
        
    }
};