class Solution {
public:
    
    int recur(int ind, string& s, vector<int>& dp){
        if(ind==s.size())return 1;
        if(dp[ind]!=-1)return dp[ind];
        int cur=0;
        if(ind!=s.size()-1 && (s[ind]=='1' || (s[ind]=='2' && s[ind+1]<='6'))){cur+=recur(ind+2,s,dp);}
        if(s[ind]!='0')cur+=recur(ind+1,s,dp);
        return dp[ind]=cur;
    }
    
    int numDecodings(string s) {
        for(int i=0;i<s.size();i++){
            if(s[i]=='0' && i==0)return 0;
            if(i!=s.size()-1 && s[i]>'2' && s[i+1]=='0')return 0;
        }
        int n=s.size();
        vector<int> dp(n+1,-1);
        return recur(0,s,dp);
    }
};