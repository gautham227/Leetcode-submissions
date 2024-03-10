class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<bool> v(1002,false);
        for(int i=0;i<nums1.size();i++)v[nums1[i]]=true;
        vector<int> ans;
        for(int j=0;j<nums2.size();j++){
            if(v[nums2[j]]){
                ans.push_back(nums2[j]);
                v[nums2[j]]=false;
            }
        }
        return ans;
    }
};