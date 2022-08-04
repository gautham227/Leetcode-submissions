class Solution {
public:
    
    int recur(int ind1, int ind2, string & str1, string & str2, vector<vector<int> >& dp){
        if(ind2<0){
            return ind1+1;
        }
        if(ind1<0)return ind2+1;
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
        if(str1[ind1]==str2[ind2]){
            return dp[ind1][ind2]=recur(ind1-1, ind2-1, str1, str2, dp);
        }
        int del=1+recur(ind1-1, ind2, str1, str2, dp);
        int ins=1+recur(ind1, ind2-1, str1, str2, dp);
        int rep=1+recur(ind1-1, ind2-1, str1, str2, dp);
        return dp[ind1][ind2]=min(del,min(ins, rep));
        
    }
    
    int minDistance(string word1, string word2) {
        int n=word1.size(), m=word2.size();
        vector<vector<int> >dp(n, vector<int>(m, -1));
        // cout<<n-1<<endl;
        return recur(n-1, m-1, word1, word2, dp);
    }
};