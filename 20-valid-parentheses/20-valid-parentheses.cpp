class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int flag=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            else{
                if(st.empty()){
                    flag=1;
                    break;
                }
                else if((st.top()=='(' && s[i]==')') || (st.top()=='[' && s[i]==']') || (st.top()=='{' && s[i]=='}') ){
                    st.pop();
                }
                else{
                    flag=1;
                    break;
                }
            }
        }
        if(!st.empty()){
            flag=1;
        }
        return 1-flag;
    }
};