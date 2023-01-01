class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int ans=true;
        int ind=0;
        vector<string> v(26,"0");
        for(int i=0;i<pattern.size();i++){
            if(v[pattern[i]-'a']=="0"){
                string s1="";
                if(ind==s.size()){
                    ans=false;
                    break;
                }
                while(s[ind]!=' ' && ind!=s.size()){
                    s1=s1+s[ind];
                    ind++;
                }
                v[pattern[i]-'a']=s1;
                if(ind!=s.size()){
                    ind++;
                }
            }
            else{
                if(ind==s.size()){
                    ans=false;
                    break;
                }
                string s1="";
                while(s[ind]!=' ' && ind!=s.size()){
                    s1=s1+s[ind];
                    ind++;
                }
                if(v[pattern[i]-'a']!=s1){
                    ans=false;
                    break;
                }
                if(ind!=s.size()){
                    ind++;
                }
            }
        }
            if(ind!=s.size()){
                ans=false;
            }
        for(int i=0;i<26;i++){
                for(int j=i+1;j<26;j++){
                    if(v[i]==v[j] && v[i]!="0" && v[j]!="0"){
                        ans=false;
                        break;
                    }
                }
            }
        return ans;
    }
};