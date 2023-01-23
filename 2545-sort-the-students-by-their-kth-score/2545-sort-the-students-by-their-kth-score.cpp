class Solution {
public:
    
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        vector<vector<int> >cur;
        for(int i=0;i<score.size();i++){
            cur.push_back({score[i][k],i});
        }
        sort(cur.begin(), cur.end());
        reverse(cur.begin(), cur.end());
        vector<vector<int> >ans;
        for(int i=0;i<cur.size();i++){
            ans.push_back(score[cur[i][1]]);
        }
        return ans;
    }
};