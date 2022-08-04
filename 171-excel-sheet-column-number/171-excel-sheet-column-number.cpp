class Solution {
public:
    int titleToNumber(string columnTitle) {
        string s=columnTitle;
        int ans=0;
        for(int i=0;i<s.size();i++){
            ans*=26;
            ans+=s[i]-'A'+1;
        }
        return ans;
    }
};