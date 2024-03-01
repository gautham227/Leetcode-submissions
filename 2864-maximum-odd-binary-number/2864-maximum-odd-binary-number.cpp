class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt1=0;
        for(int i=0;i<s.size();i++){
            cnt1+=(s[i]=='1');
        }
        string ans="";
        for(int i=0;i<s.size();i++){
            if(i<cnt1-1){
                ans.push_back('1');
            }
            else{
                ans.push_back('0');
            }
        }
        ans[ans.size()-1]='1';
        return ans;
    }
};