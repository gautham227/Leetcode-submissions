class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int ind1=0, ind2=0;
        while(ind1<nums1.size() && ind2<nums2.size()){
            if(nums1[ind1]==nums2[ind2])return nums1[ind1];
            if(nums1[ind1]>nums2[ind2])ind2++;
            else ind1++;
        }
        return -1;
    }
};