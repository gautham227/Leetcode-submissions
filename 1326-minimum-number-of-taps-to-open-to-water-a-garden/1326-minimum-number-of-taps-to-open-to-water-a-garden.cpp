class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<vector<int>> taps;
        for(int i=0;i<ranges.size();i++){
            taps.push_back({i-ranges[i], i+ranges[i]});
        }
        int ans=0;
        int last=0;
        int ma=0;
        
        sort(taps.begin(), taps.end());
        
        for(int i=0;i<taps.size();i++){
            if(taps[i][0]>ma)return -1;
            if(taps[i][0]>last){
                ans++;
                last=ma;
            }
            ma=max(ma, taps[i][1]);
        }
        
        if(last<n){
            ans++;
            last=ma;
        }
        if(last<n)return -1;
        return ans;
    }
};