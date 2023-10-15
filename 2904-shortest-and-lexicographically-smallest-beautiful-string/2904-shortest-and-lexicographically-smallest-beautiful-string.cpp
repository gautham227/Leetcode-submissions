class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans="";
        string s1="";
        int len=10000;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                int cnt1=0;
                s1.clear();
                for(int k=i;k<=j;k++){
                    s1.push_back(s[k]);
                    if(s[k]=='1')cnt1++;
                }
                
                if(cnt1==k && s1.size()<=len){
                    if(len>s1.size()){
                        ans=s1;
                    }
                    else{
                        ans=min(ans,s1);
                    }
                    len=ans.size();
                }
                
            }
        }
        if(len==10000)return "";
        return ans;
    }
};