class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> first(26,-1);
        vector<int> last(26,-1);
        for(int i=0;i<s.size();i++){
            if(first[s[i]-'a']==-1)first[s[i]-'a']=i;
            else last[s[i]-'a']=i;
        }
        int ma=INT_MIN;
        for(int i=0;i<26;i++){
            ma=max(ma, last[i]-first[i]);
        }
        return ma-1;
    }
};