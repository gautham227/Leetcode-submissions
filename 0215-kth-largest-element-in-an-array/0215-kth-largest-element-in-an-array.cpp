class Solution {
public:
    
    int medianOfmedian(vector<int>& nums){
        if(nums.size()<=5)return nums[nums.size()/2];
        vector<int> medians;
        vector<int> temp;
        for(int i=0;i<nums.size();i++){
            if((i%5)==0 && i!=0){
                sort(temp.begin(), temp.end());
                medians.push_back(temp[temp.size()/2]);
                temp.clear();
            }
            temp.push_back(nums[i]);
        }
        if(temp.size()!=0){
            sort(temp.begin(), temp.end());
            medians.push_back(temp[temp.size()/2]);
            temp.clear();
        }
        return medianOfmedian(medians);
    }
    
    int quickSelect(vector<int>& nums, int k){
        int median = medianOfmedian(nums);
        int ind = 0;
        vector<int> less, greater, equal;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<median){
                less.push_back(nums[i]);
            }
            else if(nums[i]==median){
                equal.push_back(nums[i]);
            }
            else{
                greater.push_back(nums[i]);
            }
        }
        if(k>less.size() && k<=less.size()+equal.size())return median;
        if(k<=less.size())return quickSelect(less,k);
        return quickSelect(greater, k-less.size()-equal.size());
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums,nums.size()-k+1);
    }
};