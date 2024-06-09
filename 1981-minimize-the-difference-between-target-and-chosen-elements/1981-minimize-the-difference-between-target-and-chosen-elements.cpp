class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        bitset<5000> cur(0);
        bitset<5000> prev(1);
        for(int i=0;i<mat.size();i++){
            for(auto ele: mat[i]){
                cur|=(prev<<ele);
            }
            prev=cur;
            cur&=0;
        }
        int ans=100000000;
        for(int i=0;i<prev.size();i++){
            if(prev[i]){
                ans=min(ans, abs(target-i));
            }
        }
        return ans;
    }
};