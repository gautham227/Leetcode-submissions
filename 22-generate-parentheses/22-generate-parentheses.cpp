class Solution {
public:
    vector<string> ans;
    void recur(int rem, int cnt, string s){
        if(rem==0 && cnt==0){
            ans.push_back(s);
            return;
        }
        if(rem>0){
            recur(rem-1,cnt+1,s+"(");
        }
        if(cnt>0){
            recur(rem,cnt-1,s+")");
        }
        return;
        
    }
    vector<string> generateParenthesis(int n) {
        string s="";
        recur(n, 0, s);
        return ans;
    }
};