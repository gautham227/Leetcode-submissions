class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> h1=heights;
        sort(h1.begin(), h1.end());
        int ans=0;
        for(int i=0;i<heights.size();i++){
            ans+=(heights[i]!=h1[i]);
        }
        return ans;
    }
};