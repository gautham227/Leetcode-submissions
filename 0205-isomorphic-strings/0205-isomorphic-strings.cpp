class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]=t[i];
        }
        for(int i=0;i<s.size();i++){
            s[i]=mp[s[i]];
        }
        unordered_set<char> c;
        for(auto ele: mp){
            c.insert(ele.second);
        }
        return (s==t && c.size()==mp.size());
    }
};