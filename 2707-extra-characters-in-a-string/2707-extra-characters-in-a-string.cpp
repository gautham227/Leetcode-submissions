class Solution {
public:
    
    
    int recur(int ind, string &s, vector<int>& dp, unordered_set<string> &st){
        if(ind>=s.size())return 0;
        if(dp[ind]!=-1)return dp[ind];
        string s2="";
        int ans=INT_MAX;
        for(int i=ind;i<s.size();i++){
            s2+=s[i];
            int curval=s2.size();
            int nextval;
            if(st.find(s2)!=st.end()){
                curval=0;
            }
            nextval=recur(i+1,s,dp,st);
            ans=min(ans,curval+nextval);
        }
        return dp[ind]=ans;
    }
    
    int minExtraChar(string s, vector<string>& dict) {
        int n=s.size();
        vector<int> dp(n+1, -1);
        unordered_set<string> st;
        for(auto ele: dict){
            st.insert(ele);
        }
        
        return recur(0,s,dp,st);
    }
};