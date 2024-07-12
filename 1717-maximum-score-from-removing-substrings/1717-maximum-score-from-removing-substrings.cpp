class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<char> st;
        if(y>x){
            for(int i=0;i<s.size();i++){
                if(s[i]=='a')s[i]='b';
                else if(s[i]=='b')s[i]='a';
            }
            swap(x,y);
        }
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(st.size()==0)st.push(s[i]);
            else if(st.top()=='a' && s[i]=='b'){ans+=x;st.pop();}
            else st.push(s[i]);
        }
        s.clear();
        while(st.size()>0){
            s.push_back(st.top());
            st.pop();
        }
        for(int i=s.size()-1;i>=0;i--){
            if(st.size()==0)st.push(s[i]);
            else if(st.top()=='b' && s[i]=='a'){ans+=y;st.pop();}
            else st.push(s[i]);
        }
        return ans;
    }
};