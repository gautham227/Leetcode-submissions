class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int ans=1;
        vector<int> last(2,0);
        last[0]=points[0][0];
        last[1]=points[0][1];
        for(int i=1;i<points.size();i++){
            if(points[i][0]<=last[1]){
                last[0]=points[i][0];
                last[1]=min(last[1],points[i][1]);
            }
            else{
                ans++;
                last[0]=points[i][0];
                last[1]=points[i][1];
            }
            // cout<<last[0]<<" "<<last[1]<<endl;
        }
        return ans;
    }
};