typedef long long ll;
class Solution {
public:
    ll inf=1e18;
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[0]!=b[0]){
            return a[0]<b[0];
        }
        return a[1]>b[1];
    }
    int numberOfPairs(vector<vector<int>>& p) {
        int ans=0;
        int n=p.size();
        sort(p.begin(), p.end(), cmp);
        ll ht=-1*inf;
        for(int i=0;i<n;i++){
            ht=-1*inf;
            for(int j=i+1;j<n;j++){
                if(i==j)continue;
                int x1=p[i][0];
                int y1=p[i][1];
                int x2=p[j][0];
                int y2=p[j][1];
                if(x1>x2 || y1<y2)continue;
                bool flag=true;
                if(y2>ht){ans++;}
                ht=max(ht,1ll*y2);
            }
        }
        return ans;
    }
};