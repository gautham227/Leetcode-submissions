class Solution {
public:
    int q(int a, int b){
        int cnt=0;
        if(b>a){
            int temp=a;
            a=b;
            b=temp;
        }
        while(a>b){
            a/=2;
            cnt++;
             while(b>a){
                b/=2;
                cnt++;
            }
        }
        return cnt+1;
    }
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            ans.push_back(q(queries[i][0], queries[i][1]));
        }
        return ans;
    }
};