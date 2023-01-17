class Solution {
public:
    int minFlipsMonoIncr(string s) {
        vector<int> v1,v2;
        int cnt1=0;
        int n=s.size();
        int cnt0=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1')cnt1++;
            else cnt0++;
            v1.push_back(cnt1);
            v2.push_back(cnt0);
        }
        for(int i=0;i<n;i++){
            v2[i]=v2[n-1]-v2[i];
        }
        int ans=min(cnt0,cnt1);
        for(int i=0;i<n;i++){
            ans=min(ans,v1[i]+v2[i]);
        }
        return ans;
    }
};