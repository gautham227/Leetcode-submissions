class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_set<int> s;
        for(auto ele: arr)s.insert(ele);
        int ans=1;
        while(k>0){
            if(s.find(ans)==s.end()){
                k--;
            }
            ans++;
        }
        return ans-1;
    }
};