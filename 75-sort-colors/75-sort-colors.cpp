class Solution {
public:
    void sortColors(vector<int>& nums) {
        int ind1=0, ind3=nums.size()-1;
        for(int i=0;i<=ind3;i++){
            if(nums[i]==0 && i==ind1){
                ind1++;
                continue;
            }
            if(nums[i]==2 && i==ind3){
                ind3--;
                continue;
            }
            if(nums[i]==0){
                swap(nums[i], nums[ind1]);
                ind1++;
                i--;
            }
            else if(nums[i]==2){
                swap(nums[i], nums[ind3]);
                ind3--;
                i--;
            }
        }
        
    }
};