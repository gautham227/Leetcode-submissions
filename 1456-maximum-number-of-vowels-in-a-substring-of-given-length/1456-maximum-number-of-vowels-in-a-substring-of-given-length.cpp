class Solution {
public:
    int maxVowels(string s, int k) {
        int ma=0;
        int cur=0;
        for(int i=0;i<min((int)s.size(),k);i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')cur++;
        }
        ma=cur;
        for(int i=k;i<(int)s.size();i++){
            i-=k;
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')cur--;
            i+=k;
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')cur++;
            ma=max(ma,cur);
        }
        
        return ma;
        
    }
};