class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int> > ans;
        int n=intervals.size();
        bool flag=false;
        for(int i=0;i<n;i++){
            if(flag){
                ans.push_back(intervals[i]);
                continue;
            }
            if(intervals[i][0]>newInterval[1]){
                ans.push_back(newInterval);
                flag=true;
                i--;
                continue;
            }
            if(intervals[i][1]<newInterval[0]){
                ans.push_back(intervals[i]);
                continue;
            }
            int mini=min(intervals[i][0], newInterval[0]);
            int ma=max(intervals[i][1], newInterval[1]);
            while(i<n && ma>=intervals[i][0]){
                ma=max(ma,intervals[i][1]);
                i++;
            }
            i--;
            ans.push_back({mini,ma});
            flag=true;
        }
        
        if(flag==false)ans.push_back(newInterval);
        return ans;
    }
};