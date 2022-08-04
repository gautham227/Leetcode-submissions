class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        // set<int> s;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]=i;
            // s.insert(nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            auto x=m.find(target-nums[i]);
            if(x!=m.end() && m[target-nums[i]]!=i){
                ans.push_back(i);
                ans.push_back(m[target-nums[i]]);
                break;
            }
        }
        return ans;
    }
};