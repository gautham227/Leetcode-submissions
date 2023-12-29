class Solution {
public:
    int minDifficulty(vector<int>& jd, int d) {
        // dp[ind][no of days left]
        if(d>jd.size())return -1;
        int n=jd.size();
        vector<int> prev(n+1, 1000000000+7), cur(n+1,1000000000+7);
        int ma=0;
        for(int i=n-1;i>=0;i--){
            ma=max(ma, jd[i]);
            prev[i]=ma;
        }
        for(int j=2;j<=d;j++){
            for(int i=n-1;i>=0;i--){
                ma=0;
                for(int k=i;k<n;k++){
                    ma=max(ma, jd[k]);
                    cur[i]=min(cur[i], ma+prev[k+1]);
                }
            }
            swap(prev,cur);
            fill(cur.begin(), cur.end(), 1000000000+7);
        }
        
        return prev[0];
    }
};