class Solution {
public:
    
    bool recur(int ind, string &s, set<string>& words, vector<int>& dp, int n){
        if(ind == s.size())return 1;
        if(dp[ind]!=-1)return dp[ind];
        int maxlen=20;
        string s1="";
        for(int i=ind; ((i<s.size()) && (maxlen>0));i++){
            maxlen--;
            s1+=s[i];
            
            if(words.find(s1)!=words.end()){
                if(recur(i+1,s,words, dp, n)){
                    return dp[ind]=1;
                }
            }
            
        }
        
        return dp[ind]=0;
        
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        set<string> s1;
        
        
        for(auto ele: wordDict){
            s1.insert(ele);
        }
        
        vector<int> dp(n+1,-1);
        
        return recur(0, s, s1, dp, s.size());
    }
};