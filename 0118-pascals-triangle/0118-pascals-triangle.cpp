#define pb push_back
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> >v;
        vector<int> u={1};
        v.pb(u);
        for(int j=1;j<numRows;j++){
            u.clear();
            u.pb(1);
            for(int i=1;i<v[v.size()-1].size();i++){
                int k=v[v.size()-1][i]+v[v.size()-1][i-1];
                u.pb(k);
            }
            u.pb(1);
            v.pb(u);
        }
        return v;
    }
};