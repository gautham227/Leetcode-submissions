class Solution {
public:
    
    int recur(int ind, int rem, vector<vector<int > >& events, vector<vector<int> >&dp){
        if(ind>=events.size() || rem==0)return 0;
        if(dp[ind][rem]!=-1)return dp[ind][rem];
        vector<int> v1{events[ind][1]+1,-1,-1};
        int ind1=lower_bound(events.begin(), events.end(),v1)-events.begin();
        return dp[ind][rem]=max(recur(ind1,rem-1,events,dp)+events[ind][2], recur(ind+1,rem,events,dp));
    }
    
    int maxValue(vector<vector<int>>& events, int k) {
        int n=events.size();
       vector<vector<int>> dp(n+1, vector<int>(k+1,-1));
        sort(events.begin(), events.end());
        return recur(0,k,events,dp);
    }
};