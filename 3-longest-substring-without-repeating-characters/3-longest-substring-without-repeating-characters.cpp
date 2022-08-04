class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int st=0;
        int ans=0;
        vector<int> v(256,-1);
        for(int i=0;i<s.size();i++){
            if(v[s[i]]!=-1){
                for(int j=st;j<v[s[i]];j++){
                    v[s[j]]=-1;
                }
                ans=max(ans,i-st);
                st=v[s[i]]+1;
                v[s[i]]=-1;
            }
            v[s[i]]=i;
        }
        ans=max(ans,(int)s.size()-st);
        return ans;
    }
};