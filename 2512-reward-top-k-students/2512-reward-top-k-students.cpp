class Solution {
public:

    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[0]!=b[0])return a[0]>b[0];
        return a[1]<b[1];
    }

    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        set<string> p, n;
        for(auto ele: positive_feedback){
            p.insert(ele);
        }
        for(auto ele: negative_feedback){
            n.insert(ele);
        }
        vector<vector<int> >v;

        int len=report.size();

        string s;
        for(int i=0;i<len;i++){
            s="";
            int val=0;
            for(int j=0;j<report[i].size();j++){
                if(report[i][j]!=' ')s.push_back(report[i][j]);
                else{
                    if(p.find(s)!=p.end())val+=3;
                    if(n.find(s)!=n.end())val-=1;
                    s="";
                }
            }

            if(p.find(s)!=p.end())val+=3;
            if(n.find(s)!=n.end())val-=1;

            v.push_back({val, student_id[i]});

        }

        sort(v.begin(), v.end(), cmp);

        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(v[i][1]);
        }

        return ans;
    }
};