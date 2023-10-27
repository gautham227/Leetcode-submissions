class Solution {
public:
    
    string longestPalindrome(string s) {
        int n=s.size();
        int ans=0, st;
        // vector<vector<bool> >dp(n, vector<bool>(n,false));
        vector<bool> cur(n, false), prev(n, false), prev2(n, false);
        // choose a particular length and calculate if all substr of that size is pal or no
        // here l is length 
        for(int l=0;l<n;l++){
            // i is starting and j is ending point of substring
            for(int i=0,j=l;j<n;i++,j++){
                if(i==j){
                    cur[i]=1;
                }
                else if(j-i==1){
                    if(s[i]==s[j]){
                        cur[i]=1;
                    }
                    else{
                        cur[i]=0;
                    }
                }
                else{
                    cur[i]=(prev2[i+1] && s[i]==s[j]);
                }
                if(cur[i]==1 && j-i+1>ans){
                    ans=j-i+1;
                    st=i;
                }
            }
            prev2 = prev;
            prev=cur;
        }
        return s.substr(st, ans);
    }
};