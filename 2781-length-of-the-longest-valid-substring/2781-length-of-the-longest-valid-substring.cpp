class Solution {
public:
    
    int recur(int ind, string & word, set<string>& forbidden, vector<int> & dp){
        if(ind>=word.size())return 0;
        if(dp[ind]!=-1)return dp[ind];
        // int cur=0;
        string cur="";
        for (int i=0;i<min(recur(ind+1,word, forbidden, dp)+1, 11);i++){
            cur+=word[ind+i];
            if(forbidden.find(cur)!=forbidden.end()){
                dp[ind]=i;
                break;
            }
        }
        
        if(dp[ind]==-1)dp[ind]=1+recur(ind+1,word, forbidden, dp);
        return dp[ind];
        
    }
    
    int longestValidSubstring(string word, vector<string>& forbidden) {
        set<string> f;
        for(auto ele: forbidden)f.insert(ele);
        int n=word.size();
        vector<int> dp(n+1,-1);
        recur(0, word, f, dp);
        
        return *max_element(dp.begin(), dp.end());
    }
};