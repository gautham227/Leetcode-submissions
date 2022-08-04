class Solution {
public:
    vector<vector<int> >ans;
    void recur(vector<int>& v, int t, int i, vector<int> &v1){
        if(t==0)ans.push_back(v1);
        if(i>=v.size())return;
        if(v[i]>t)return;
        else{
            recur(v,t,i+1,v1);
            v1.push_back(v[i]);
            recur(v,t-v[i],i,v1);
            v1.pop_back();
        }
        return;
    }
    
    vector<vector<int>> combinationSum(vector<int>& v, int t) {
        sort(v.begin(),v.end());
        vector<int> v1;
        recur(v,t,0,v1);
        return ans;
    }
};