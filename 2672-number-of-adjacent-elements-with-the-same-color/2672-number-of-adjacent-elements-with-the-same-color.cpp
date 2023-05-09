class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        int cnt=0;
        vector<int> cur(n+2,0);
        for(int i=0;i<queries.size();i++){
            if(cur[queries[i][0]+1]!=0){
                if(cur[queries[i][0]+1]==cur[queries[i][0]]){
                    cnt--;
                }
                if(cur[queries[i][0]+1]==cur[queries[i][0]+2]){
                    cnt--;
                }
            }
            cur[queries[i][0]+1]=queries[i][1];
            if(cur[queries[i][0]+1]==cur[queries[i][0]]){
                cnt++;
            }
            if(cur[queries[i][0]+1]==cur[queries[i][0]+2]){
                cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};