class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            set<int> s1,s2;
            for(int j=0;j<n;j++){
                if(j<=i){
                    s1.insert(nums[j]);
                }
                else{
                    s2.insert(nums[j]);
                }
            }
            ans.push_back(s1.size()-s2.size());
            s1.clear();
            s2.clear();
        }
        return ans;
    }
};