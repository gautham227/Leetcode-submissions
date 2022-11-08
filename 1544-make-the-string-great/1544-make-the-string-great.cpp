class Solution {
public:
    string makeGood(string s) {
        if(s.size()==1)return s;
        string s1="";
        int n=s.size();
        int cnt=1;
        while(cnt!=0 && s.size()>1){
            cnt=0;
            s1.clear();
            int i=0;
            for(i=0;i<s.size()-1;i++){
                if(s[i]==s[i+1]+32 || s[i]+32==s[i+1]){
                    i++;
                    cnt++;
                }
                else{
                    s1.push_back(s[i]);
                }
            }
            if(i<s.size()){
                s1.push_back(s[i]);
            }
            s=s1;
        }
        return s;
    }
};