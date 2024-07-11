class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        string cur;
        for(auto c: s){
            if(c=='(')st.push(cur.size());
            else if(c==')'){
                int sta=st.top();
                st.pop();
                reverse(cur.begin()+sta, cur.end());
            }
            else{
                cur.push_back(c);
            }
        }
        return cur;
    }
};