class Solution {
public:
    
    bool check(vector<int>& nums, int val, int p){
        for(int i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1]<=val){
                p--;
                i++;
            }
        }
        return (p<=0);
    }
    
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        
        int l=0, r=1000000000;
        
        while(r-l>1){
            int mid=l+(r-l)/2;
            if(check(nums, mid, p)){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        
        if(check(nums, l, p))return l;
        return r; 
    }
};