class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                s.insert(nums[i]);
            }
        }
        int sz=s.size();
        
        for(int i=1;i<=sz+1;i++){
            if(s.find(i)==s.end())return i;
        }
        return 1;
    }
};