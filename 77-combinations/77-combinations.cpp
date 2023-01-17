class Solution {
public:
    vector<vector<int> >ans;
    void recur(int cur, int n, int used, int k, vector<int>& v){
        if(used==k){
            ans.push_back(v);
            return;
        }
        if(cur>n)return;
        recur(cur+1,n,used,k,v);
        v.push_back(cur);
        recur(cur+1,n,used+1,k,v);
        v.pop_back();
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>v;
        recur(1,n,0,k,v);
        return ans;
    }
};