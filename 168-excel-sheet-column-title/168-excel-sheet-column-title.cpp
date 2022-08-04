class Solution {
public:
    string convertToTitle(int x) {
        string s;
        while(x>0){
            int y=x%26;
            if(y==0){
                s.push_back('Z');
                x-=26;
            }
            else{
                s.push_back('A'+(y-1));   
            }
            x/=26;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};