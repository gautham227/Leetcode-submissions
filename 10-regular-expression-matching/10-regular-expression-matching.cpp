class Solution {
public:
    int dp[32][32];
    int n,m;
    int recur(int ind1, int ind2, string& s, string& p){
        if(ind1>=n){
            int flag=1;
            while(ind2<m){
                if(p[ind2]!='*'){
                    if(ind2!=m-1 && p[ind2+1]=='*'){
                        ind2++;
                        continue;
                    }
                    flag=0;
                    break;
                }
                ind2++;
            }
            return dp[ind1][ind2]=flag;
        }
        if(ind2>=m){
            return 0;
        }
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
        if(p[ind2]=='.'){
            if(ind2!=m-1 && p[ind2+1]=='*')return dp[ind1][ind2]=recur(ind1+1, ind2, s, p)||recur(ind1, ind2+1, s, p);
            return dp[ind1][ind2]=recur(ind1+1, ind2+1, s,p);
        }
        else if(p[ind2]=='*'){
            if(p[ind2-1]==s[ind1] || p[ind2-1]=='.'){
                return dp[ind1][ind2]=recur(ind1+1, ind2, s,p) || recur(ind1, ind2+1, s,p);
            }
            else{
                return dp[ind1][ind2]=recur(ind1,ind2+1,s,p);
            }
        }
        else if(s[ind1]!=p[ind2]){
            if(ind2==m-1)return dp[ind1][ind2]=false;
            if(p[ind2+1]=='*')return dp[ind1][ind2]=recur(ind1,ind2+1,s,p);
            return dp[ind1][ind2]=false;
        }
        if(ind2!=m-1 && p[ind2+1]=='*')return dp[ind1][ind2]=recur(ind1+1, ind2, s, p)||recur(ind1, ind2+1, s, p);
        return dp[ind1][ind2]=recur(ind1+1, ind2+1, s, p);
    }
    
    bool isMatch(string s, string p) {
        memset(dp,-1,sizeof dp);
        n=s.size();
        m=p.size();
        return recur(0,0,s,p);
    }
};