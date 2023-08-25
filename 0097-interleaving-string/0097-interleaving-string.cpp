class Solution {
public:
    
    bool recur(int ind1, int ind2, string&s1, string& s2, string &s3, vector<vector<int> >& dp){
        if(ind1+ind2>=s3.size())return true;
        if(ind1+ind2==s3.size()-1){
            if(ind1!=s1.size() && s3[ind1+ind2]==s1[ind1])return 1;
            if(ind2!=s2.size() && s3[ind1+ind2]==s2[ind2])return 1;
            return false;
        }
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
        bool l=false, r=false;
        if(ind1!=s1.size() && s1[ind1]==s3[ind1+ind2]){
            l=recur(ind1+1,ind2,s1,s2,s3,dp);
        }
        if(ind2!=s2.size() && s2[ind2]==s3[ind1+ind2]){
            r=recur(ind1,ind2+1,s1,s2,s3,dp);
        }
        return dp[ind1][ind2]=l+r;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        bool ans=true;
        if(s3.size()!=s1.size()+s2.size())return false;
        vector<vector<int> >dp(s1.size()+1, vector<int> (s2.size()+1, -1));
        return recur(0,0,s1,s2,s3,dp);
    }
};