class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int num=0;
        int ind=1;
        for(int & x: nums){
            num^=x;
            num^=ind;
            ind++;
        }
        return num;
    }
};