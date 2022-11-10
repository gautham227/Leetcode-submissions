class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> s1;
        for(int i=0;i<s.size();i++){
            if(s1.empty()==false && s1.top()==s[i])s1.pop();
            else s1.push(s[i]);
        }
        string s2="";
        while(s1.empty()==false){
            s2.push_back(s1.top());
            s1.pop();
        }
        reverse(s2.begin(), s2.end());
        return s2;
    }
};