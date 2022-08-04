class Solution {
public:
    vector<vector<int>> ans;
    void recur(vector<int> & v, int ind){
        if(ind>=v.size()){ans.push_back(v);return;}
        for(int i=ind;i<v.size();i++){
            swap(v[ind],v[i]);
            recur(v,ind+1);
            swap(v[ind],v[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        recur(nums,0);
        return ans;
    }
};