class Solution {
public:
    
    bool recur(int ind, int cnt, string& s, vector<vector<int> >& dp){
        if(cnt<0)return false;
        if(ind==s.size()){
            if(cnt==0)return true;
            return false;
        }
        if(dp[ind][cnt]!=-1)return dp[ind][cnt];
        if(s[ind]=='('){
            return dp[ind][cnt]=recur(ind+1,cnt+1,s,dp);
        }
        else if(s[ind]==')'){
            return dp[ind][cnt]=recur(ind+1,cnt-1,s,dp);
        }
        return dp[ind][cnt]=recur(ind+1,cnt+1,s,dp) | recur(ind+1,cnt-1,s,dp) | recur(ind+1,cnt,s,dp);
    }
    
    bool checkValidString(string s) {
        int n=s.size();
        vector<vector<int> > dp(n+2,vector<int>(n+2, -1));
        return recur(0,0,s,dp);
    }
};