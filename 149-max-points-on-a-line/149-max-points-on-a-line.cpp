class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        int ans=1;
        for(int i=0;i<n;i++){
            map<double,int> mp;
            for(int j=0;j<n;j++){
                if(j==i)continue;
                mp[atan2((points[j][1]-points[i][1]),(points[j][0]-points[i][0]))]++;
            }
            for(auto ele: mp){
                ans=max(ans,ele.second+1);
            }
        }
        return ans;
    }
};