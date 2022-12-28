class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> mp1,mp2;
        int n=nums1.size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mp1[nums1[i]+nums2[j]]++;
                mp2[nums3[i]+nums4[j]]++;
            }
        }
        
        int ans=0;
        for(auto ele: mp1){
            ans+=mp2[-1*ele.first]*ele.second;
        }
        
        return ans;
    }
};