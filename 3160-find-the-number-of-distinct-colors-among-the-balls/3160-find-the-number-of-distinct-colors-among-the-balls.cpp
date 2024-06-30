class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        cout<<limit<<endl;
        map<int,int> cntr;
        cntr[0]+=limit+1;
        vector<int> ans;
        map<int, int> clr;
        for(int i=0;i<queries.size();i++){
            cntr[clr[queries[i][0]]]--;
            if(cntr[clr[queries[i][0]]]==0){
                cntr.erase(cntr.find(clr[queries[i][0]]));
            }
            cntr[queries[i][1]]++;
            clr[queries[i][0]]=queries[i][1];
            ans.push_back(cntr.size()-(cntr.find(0)!=cntr.end()));
        }
        
        return ans;
        
    }
};