class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<pair<int,int> >v;
        for(int i=0;i<n+1;i++){
            v.push_back({0,0});
        }
        for(auto ele: trust){
            v[ele[0]].second++;
            v[ele[1]].first++;
        }
        for(int i=1;i<n+1;i++){
            if(v[i].first==n-1 && v[i].second==0)return i;
        }
        return -1;
    }
};