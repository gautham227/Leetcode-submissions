class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {
        unordered_map<long long,long long> s;
        for(auto ele: coordinates)s[ele[0]*(1ll*10000000)+ele[1]]+=1;
        long long ans=0;
        for(long long i=0;i<coordinates.size();i++){
            for(long long j=0;j<=k;j++){
                long long x1=coordinates[i][0]^j;
                long long y1=(k-j)^coordinates[i][1];
                ans+=s[x1*(1ll*10000000)+y1];
                if(coordinates[i][0]==x1 && coordinates[i][1]==y1)ans--;
            }
        }
        return ans/2;
    }
};