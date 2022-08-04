class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        if(a.size()<b.size())swap(a,b);
        int c=0;
        for(int i=0;i<b.size();i++){
            if(a[a.size()-1-i]=='0' && b[b.size()-1-i]=='0' && c==0){
                ans.push_back('0');
                c=0;
            }
            else if(a[a.size()-1-i]=='0' && b[b.size()-1-i]=='0' && c==1){
                ans.push_back('1');
                c=0;
            }
            else if(a[a.size()-1-i]=='1' && b[b.size()-1-i]=='1' && c==0){
                ans.push_back('0');
                c=1;
            }
            else if(a[a.size()-1-i]=='1' && b[b.size()-1-i]=='1' && c==1){
                ans.push_back('1');
                c=1;
            }
            else if(a[a.size()-1-i]=='1' && b[b.size()-1-i]=='0' && c==0){
                ans.push_back('1');
                c=0;
            }
            else if(a[a.size()-1-i]=='1' && b[b.size()-1-i]=='0' && c==1){
                ans.push_back('0');
                c=1;
            }
            else if(a[a.size()-1-i]=='0' && b[b.size()-1-i]=='1' && c==0){
                ans.push_back('1');
                c=0;
            }
            else if(a[a.size()-1-i]=='0' && b[b.size()-1-i]=='1' && c==1){
                ans.push_back('0');
                c=1;
            }
        }
        for(int i=b.size();i<a.size();i++){
            if(a[a.size()-1-i]=='0' && c==1){
                ans.push_back('1');
                c=0;
            }
            else if(a[a.size()-1-i]=='0' && c==0){
                ans.push_back('0');
                c=0;
            }
            else if(a[a.size()-1-i]=='1' && c==0){
                ans.push_back('1');
                c=0;
            }
            else if(a[a.size()-1-i]=='1' && c==1){
                ans.push_back('0');
                c=1;
            }  
        }
        if(c==1){
            ans.push_back('1');
            c=0;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};