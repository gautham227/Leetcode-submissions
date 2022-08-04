class Solution {
public:
    vector<vector<int>> ans;
    void recur(vector<int> &v, int ind){
        if(ind>=v.size()){ans.push_back(v);return;}
        for(int i=ind;i<v.size();i++){
            if(i!=ind && v[i]==v[ind])continue;
            swap(v[ind],v[i]);
            recur(v,ind+1);
            // swap(v[ind],v[i]);
        }
        for(int i=v.size()-1;i>=ind;i--){
            swap(v[i],v[ind]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        recur(nums,0);
        return ans;
    }
};