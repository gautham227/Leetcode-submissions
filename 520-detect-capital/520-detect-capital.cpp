class Solution {
public:
    bool detectCapitalUse(string words) {
        int cnt=0;
        for(int i=0;i<words.size();i++){
            if(words[i]>='A' && words[i]<='Z')cnt++;
        }
        
        if(cnt==words.size())return true;
        if(cnt==0 || (cnt==1 && words[0]>='A' && words[0]<='Z'))return true;
        return false;
    }
};