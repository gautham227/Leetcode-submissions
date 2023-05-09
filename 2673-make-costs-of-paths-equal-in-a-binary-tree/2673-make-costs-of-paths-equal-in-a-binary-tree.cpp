class Solution {
public:
    
    int ans;
    
    int recur(int ind, vector<int> & cost, int n){
        if(2*ind>n)return cost[ind-1];
        int left=recur(2*ind, cost, n);
        int right=recur(2*ind+1, cost, n);
        ans+=abs(left-right);
        return max(left, right)+cost[ind-1];
    }
    
    int minIncrements(int n, vector<int>& cost) {
        ans=0;
        recur(1,cost,n);
        return ans;
    }
};