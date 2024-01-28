class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                matrix[i][j]+=matrix[i][j-1];
            }
        }
        int ans=0;
        for(int st=0;st<m;st++){
            for(int en=st;en<m;en++){
                unordered_map<int,int> mp;
                mp[0]=1;
                int su=0;
                for(int i=0;i<n;i++){
                    su+=matrix[i][en];
                    if(st!=0){
                        su-=matrix[i][st-1];
                    }
                    ans+=mp[su-target];
                    mp[su]+=1;
                }
            }
        }
        return ans;
    }
};