class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int> >mp;
        for(int i=0;i<groupSizes.size();i++){
            mp[groupSizes[i]].push_back(i);
        }
        vector<vector<int> >ans;
        for(auto &ele: mp){
            vector<int> cur;
            int ind=0;
            while(ind<ele.second.size()){
                cur.push_back(ele.second[ind]);
                if(cur.size()==ele.first){
                    ans.push_back(cur);
                    cur.clear();
                }
                ind++;
            }
        }
        return ans;
    }
};