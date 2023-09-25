class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> v(26,0);
        for(auto &ele: s)v[ele-'a']--;
        for(auto &ele: t)v[ele-'a']++;
        for(int i=0;i<26;i++)if(v[i])return i+'a';
        return 'a';
    }
};