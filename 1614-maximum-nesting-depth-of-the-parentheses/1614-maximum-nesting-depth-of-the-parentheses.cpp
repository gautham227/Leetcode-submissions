class Solution {
public:
    int maxDepth(string s) {
        int ans=0;
        int cur=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                cur++;
                ans=max(ans, cur);
            }
            else if(s[i]==')'){
                cur--;
            }
        }
        return ans;
    }
};