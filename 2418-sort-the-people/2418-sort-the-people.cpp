class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string> >v;
        int n=names.size();
        for(int i=0;i<n;i++){
            v.push_back({-1*heights[i], names[i]});
        }
        sort(v.begin(),v.end());
        names.clear();
        for(int i=0;i<n;i++){
            names.push_back(v[i].second);
        }
        return names;
    }
};