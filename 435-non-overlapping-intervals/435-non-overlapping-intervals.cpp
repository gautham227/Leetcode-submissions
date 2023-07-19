class Solution {
public:
    
    static bool order(vector<int> &x, vector<int> &y){
        return x[1]<y[1];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), order);
        
        int last=INT_MIN;
        
        int ans=0;
        
        for(int i=0;i<intervals.size();i++){
            if(intervals[i][0]>=last){
                last=intervals[i][1];
            }
            else ans++;
        }
        
        return ans;
    }
};