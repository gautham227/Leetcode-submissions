class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lo=0, hi=numbers.size()-1,s;
        while(lo<hi){
            s=numbers[lo]+numbers[hi];
            if(s==target){
                return {lo+1, hi+1};
            }
            if(s>target){
                hi--;
            }
            else{
                lo++;
            }
        }
        return{lo,hi};
    }
};