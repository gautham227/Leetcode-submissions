class Solution {
public:
    bool cmp(vector<int> a, vector<int> b){
        if(a[0]>b[0])return true;
        if(a[1]>b[1])return true;
        return false;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<vector<int>> a;
        for(int i=0;i<mat.size();i++){
            // vector<int> v;
            int cnt=0;
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==1)cnt++;
                else{break;}
            }
            a.push_back({cnt,i});
        }
        sort(a.begin(),a.end());
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(a[i][1]);
        }
        return ans;
    }
};