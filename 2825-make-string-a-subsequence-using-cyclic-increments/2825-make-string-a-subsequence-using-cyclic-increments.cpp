class Solution {
public:
    
    bool checknext(char a, char b){
        if(b-a==1)return true;
        if(a=='z' && b=='a')return true;
        return false;
    }
    
    bool canMakeSubsequence(string str1, string str2) {
        int n=str1.size();
        int n1=str2.size();
        int ind=0;
        for(int i=0;i<n;i++){
            if(str1[i]==str2[ind] || checknext(str1[i], str2[ind])){
                ind++;
                if(ind==n1)return true;
            }
        }
        return false;
    }
};