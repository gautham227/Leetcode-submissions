class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int req=accumulate(apple.begin(), apple.end(), 0);
        sort(capacity.begin(), capacity.end());
        int ind=capacity.size()-1;
        int ans=0;
        while(req>0){
            ans++;
            req-=capacity[ind];
            ind--;
        }
        return ans;
    }
};