class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int> >ans;
        sort(nums.begin(), nums.end());
        int n=nums.size();
        for(int i=0;i<n;i+=3){
            vector<int> cur;
            for(int j=i;j<i+3;j++){
                cur.push_back(nums[j]);
            }
            if(cur[2]-cur[0]>k)return {};
            ans.push_back(cur);
        }
        return ans;
    }
};