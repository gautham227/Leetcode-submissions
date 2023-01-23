class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        if(s==target)return true;
        int cnt1=0;
                int req1=0;

        for(int i=0;i<s.size();i++){
            if(s[i]=='1')cnt1++;
            if(target[i]=='1')req1++;
        }
        int cnt0=s.size()-cnt1;
        int req0=target.size()-req1;
        bool flag=true;
        if(cnt1>0 && req1==0)flag=false;
        if(cnt1==0 && req1>0)flag=false;
        return flag;
    }
};