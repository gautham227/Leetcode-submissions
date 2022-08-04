class Solution {
public:
    vector<int> vals;
    vector<vector<int>> ans;
    
    void recur(int t,int ind, vector<int>& req){
        if(t==0){ans.push_back(req);return;}
        if(ind>=vals.size())return;
        if (ind+1>t)return;
        if(vals[ind]==0){
            recur(t,ind+1,req);
        }
        else{
            recur(t,ind+1, req);
            req.push_back(ind+1);
            vals[ind]--;
            recur(t-ind-1,ind, req);
            vals[ind]++;
            req.pop_back();
        }
        return;
    }
    
    vector<vector<int>> combinationSum2(vector<int>& v, int t) {
        for(int i=0;i<30;i++){
            vals.push_back(0);
        }
        vector<int> req;
        for(int i=0;i<v.size();i++){
            if(v[i]<31){
                vals[v[i]-1]++;
            }
        }
        recur(t,0,req);
        return ans;
    }
};