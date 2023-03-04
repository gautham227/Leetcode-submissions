class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        vector<int> l,r;
        vector<int> ans;
        int n=nums.size();
        l.push_back(0);
        r.push_back(0);
        int su=0;
        int su1=0;
        for(int i=0;i<n;i++){
            l.push_back(l[i]+nums[i]);
            r.push_back(r[i]+nums[n-1-i]);
        }
        reverse(r.begin(), r.end());
        for(int i=0;i<n;i++){
            ans.push_back(abs(r[i+1]-l[i]));
        }
        return ans;              
    }
};