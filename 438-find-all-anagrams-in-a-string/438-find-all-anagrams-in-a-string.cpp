class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size()>s.size())return {};
        vector<int> m1(26,0);
        vector<int> m2(26,0);
        for(int i=0;i<p.size();i++){
            m1[p[i]-'a']++;
        }
        vector<int> ans;
        for(int i=0;i<s.size();i++){
            if(i<p.size()-1){
                m2[s[i]-'a']++;
            }
            else{
                m2[s[i]-'a']++;
                if(m1==m2)ans.push_back(i-p.size()+1);
                m2[s[i-p.size()+1]-'a']--;
            }
        }
        return ans;
    }
};