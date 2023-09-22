class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ind1=0, ind2=0;
        while(ind1<s.size() && ind2<t.size()){
            while(ind2<t.size() && s[ind1]!=t[ind2]){
                ind2++;
            }
            if(ind2<t.size() && s[ind1]==t[ind2]){ind1++;ind2++;}
        }
        return (ind1==s.size());
    }
};