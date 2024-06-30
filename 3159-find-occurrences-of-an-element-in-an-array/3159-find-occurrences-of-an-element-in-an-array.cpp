class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> ind;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==x){
                ind.push_back(i);
            }
        }
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            if(ind.size()<queries[i])ans.push_back(-1);
            else ans.push_back(ind[queries[i]-1]);
        }
        return ans;
    }
};