class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> c1, c2;
        for(int i=0;i<s.size();i++){
            if(s[i]!='#'){
                c1.push(s[i]);
            }
            else if(c1.size()>0){
                c1.pop();
            }
        }
        for(int i=0;i<t.size();i++){
            if(t[i]!='#'){
                c2.push(t[i]);
            }
            else if(c2.size()>0){
                c2.pop();
            }
        }
        return (c1==c2);
    }
};