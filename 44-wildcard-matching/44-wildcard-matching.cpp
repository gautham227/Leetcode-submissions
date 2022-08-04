class Solution {
public:
    
    int recur(int ind1, int ind2, string& p, string& text, vector<vector<int> >&dp){
    //     cout<<ind1<<" "<<ind2<<endl;
        if(ind1<0 && ind2<0)return 1;
        if(ind2<0){
            for(int i=0;i<=ind1;i++){
                if(p[i]!='*')return 0;
            }
            return 1;
        }
        if(ind1<0)return 0;
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
        if(p[ind1]!='*'){
            if(p[ind1]!=text[ind2] && p[ind1]!='?')return dp[ind1][ind2]=0;
            return dp[ind1][ind2]=recur(ind1-1,ind2-1,p,text,dp);
        }
        while(ind1>=1 && p[ind1-1]=='*'){
            ind1--;
        }
        if(recur(ind1,ind2-1,p,text,dp)==1){
            return dp[ind1][ind2]=1;
        }
        return dp[ind1][ind2]=recur(ind1-1,ind2,p,text,dp);
    }

    bool isMatch(string s, string p) {
        int n=p.size(), m=s.size();
        vector<vector<int> >dp(n, vector<int>(m,-1));
        return recur(n-1,m-1,p,s,dp);
    }
};