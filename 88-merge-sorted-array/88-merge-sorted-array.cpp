//coded by gautham on jan 19th
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int t=n+m;
        while(n>0 && m>0){
            if(nums1[m-1]>nums2[n-1]){
                nums1[t-1]=nums1[m-1];
                m--;
            }
            else{
                nums1[t-1]=nums2[n-1];
                n--;
            }
            t--;
        }
        while(n>0){
            nums1[n-1]=nums2[n-1];
            n--;
        }
        return;
    }
};