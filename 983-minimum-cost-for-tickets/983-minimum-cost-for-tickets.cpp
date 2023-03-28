class Solution {
public:
    
    int recur(int ind, vector<int>& dp, vector<int>& costs, vector<int>& days){
        if(ind==days.size())return 0;
        if(dp[ind]!=-1)return dp[ind];
        int ans=INT_MAX;
        ans=min(costs[0]+recur(ind+1,dp,costs,days),ans);
        int ind1=ind;
        int n=days.size();
        while(ind1!=n && days[ind1]<days[ind]+7){
            ind1++;
        }
        ans=min(costs[1]+recur(ind1,dp,costs,days),ans);
        while(ind1!=n && days[ind1]<days[ind]+30){
            ind1++;
        }
        ans=min(costs[2]+recur(ind1,dp,costs,days),ans);
        return dp[ind]=ans;
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int> dp(366, -1);
        return recur(0,dp,costs,days);
    }
};