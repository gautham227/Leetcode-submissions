class Solution {
public:
    static bool cmp(string &s1, string& s2){
        return s1.size()<s2.size();
    }
    
    bool compare(string& s1, string & s2){
        if(s1.size()!=s2.size()+1)return false;
        int cnt=0;
        int ind1=0, ind2=0;
        for(int i=0;i<s2.size();i++){
            if(s1[ind1]!=s2[ind2]){
                cnt++;
                ind1++;
            }
            else{
                ind1++;
                ind2++;
            }
        }
        if(cnt==0 || (cnt==1 && s1[ind1]==s2[ind2])){
            return true;
        }
        return false;
    }
    
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(), words.end(), cmp);
        vector<int> dp(n, 1);
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(dp[i]<dp[j]+1 && compare(words[i], words[j])){
                    dp[i]=dp[j]+1;
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};