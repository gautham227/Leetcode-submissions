class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ind1=0, ind2=nums.size()-1;
        int r=nums.size()-count(nums.begin(), nums.end(), val);
        while(ind2>=0 && nums[ind2]==val)ind2--;
        while(ind1<ind2){
            if(nums[ind1]==val){
                nums[ind1]=nums[ind2];
                ind2--;
                while(ind2>=ind1 && nums[ind2]==val)ind2--;
            }
            ind1++;
        }
        return r;
    }
};