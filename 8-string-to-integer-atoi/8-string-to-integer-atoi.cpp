class Solution {
public:
    int myAtoi(string s) {
        if(s=="")return 0;
        else if(s==" ")return 0;
        long long ans=0;
        int k=1;
        int ind=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                ind=i;
                break;
            }
        }
        // cout<<ind<<endl;
        if(s[ind]=='-' || s[ind]=='+'){
            if(s[ind]=='-'){
                k=-1;
            }
            ind++;
        }
        for(int i=ind;i<s.size();i++){
            if(s[i]-'0'>=0 && s[i]-'0'<=9){
                ans=1LL*ans*10+(s[i]-'0');
                if(ans>INT_MAX){
                    break;
                }
                else if(ans<INT_MIN){
                    break;
                }
            }
            else{
                break;
            }
        }
        ans=ans*k;
        // cout<<ans<<endl;
        if(ans>INT_MAX){
            return INT_MAX;
        }
        else if(ans<INT_MIN){
            return INT_MIN;
        }
        return ans;
    }
    
};