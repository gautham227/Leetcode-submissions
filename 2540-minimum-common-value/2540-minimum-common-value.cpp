class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1, s2;
        for(auto ele: nums1)s1.insert(ele);
        for(auto ele: nums2)s2.insert(ele);
        for(auto ele: s1){
            if(s2.find(ele)!=s2.end()){
                return ele;
            }
        }
        return -1;
    }
};