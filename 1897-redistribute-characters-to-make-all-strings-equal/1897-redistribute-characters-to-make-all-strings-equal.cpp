class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int v[26];
        memset(v,0,sizeof(v));
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
                v[words[i][j]-'a']++;
            }
        }
        for(int i=0;i<26;i++){
            if(v[i]%words.size()!=0)return false;
        }
        return true;
    }
};