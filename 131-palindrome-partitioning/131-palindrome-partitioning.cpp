class Solution {
public:
    vector<vector<string> >ans;
    bool checkpal(string &s, int st, int en){
        for(int i=0;i<=(en-st)/2;i++){
            if(s[st+i]!=s[en-i])return false;
        }
        return true;
    }
    void recur(string &s,int ind,vector<string>& cur){
        if(ind==s.size()){
            ans.push_back(cur);
            return;
        }
        for(int i=ind;i<s.size();i++){
            if(checkpal(s,ind,i)){
                cur.push_back(s.substr(ind,i-ind+1));
                recur(s,i+1,cur);
                cur.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        vector<string> cur;
        recur(s,0,cur);
        return ans;
    }
};