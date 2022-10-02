class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        vector<int> cur;
        int ind;
        for(auto x: nums){
            if(lower_bound(cur.begin(), cur.end(), x)==cur.end()){
                cur.push_back(x);
            }
            else{
                ind=lower_bound(cur.begin(), cur.end(), x)-cur.begin();
                cur[ind]=x;
            }
        }
        return cur.size();
    }
};