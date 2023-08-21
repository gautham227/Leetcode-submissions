class Solution {
public:
    
    map<int, vector<vector<int> > >mp;
    
    int recur(int last, vector<int>& dp){
        if(last<0)return 0;
        if(dp[last]!=-1)return dp[last];
        int cur=recur(last-1, dp);
        for(auto ele: mp[last]){
            cur=max(cur, ele[1]+recur(ele[0]-1, dp));
        }
        return dp[last]=cur;
    }
    
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        for(auto ele: offers){
            mp[ele[1]].push_back({ele[0], ele[2]});
        }
        
        vector<int> dp(100000+10, -1);
        
        return recur(n-1, dp);
        
    }
};