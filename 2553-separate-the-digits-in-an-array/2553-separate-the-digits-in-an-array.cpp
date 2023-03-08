class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int ele=nums[i];
            vector<int> cur;
            while(ele>0){
                cur.push_back(ele%10);
                ele/=10;
            }
            for(int j=cur.size()-1;j>=0;j--){
                ans.push_back(cur[j]);
            }
        }
        return ans;
    }
};