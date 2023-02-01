class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        int sz=min(n,m);
        string ans="";
        string cur="";
        for(int i=0;i<sz;i++){
            cur.push_back(str1[i]);
            if(n%(i+1)!=0 || m%(i+1)!=0)continue;
            int cursz=i+1;
            bool flag=true;
            for(int j=0;j<n;j++){
                if(str1[j]!=cur[j%cursz])flag=false;
            }
            for(int j=0;j<m;j++){
                if(str2[j]!=cur[j%cursz])flag=false;
            }
            if(flag)ans=cur;
        }
        return ans;
    }
};