class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        bool ans=false;
        int len=0;
        int n=s.size();
        string s1="";
        for(int i=0;i<n-1;i++){
            s1+=s[i];
            len++;
            int ind=0;
            bool cur=true;
            if(n%len!=0){
                continue;
            }
            for(int j=0;j<n ;j++){
                if(s[j]!=s1[ind]){
                    cur=false;
                    break;
                }
                ind++;
                ind%=len;
            }
            ans|=cur;
        }
        return ans;
    }
};