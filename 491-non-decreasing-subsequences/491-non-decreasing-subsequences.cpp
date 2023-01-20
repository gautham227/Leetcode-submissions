class Solution {
public:
    set<vector<int> >ans;

    void recur(int ind, int n, vector<int>& nums, vector<int>& cur){
        cout<<ind<<endl;
        if(ind==n)return;
        if(cur.size()==0 || cur[cur.size()-1]<=nums[ind]){
            cur.push_back(nums[ind]);
            if(cur.size()>1)ans.insert(cur);
            recur(ind+1,n,nums,cur);
            cur.pop_back();
        }
        recur(ind+1,n,nums,cur);
        return;
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> v;
        recur(0,nums.size(),nums,v);
        vector<vector<int> > ans1;
        for(auto ele: ans)ans1.push_back(ele);
        return ans1;
    }
};