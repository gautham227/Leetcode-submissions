class Solution {
public:
    bool isItPossible(string word1, string word2) {
        vector<int> cnt1(26,0);
        vector<int> cnt2(26,0);
        
        for(int i=0;i<word1.size();i++){
            cnt1[word1[i]-'a']++;
        }
        for(int i=0;i<word2.size();i++){
            cnt2[word2[i]-'a']++;
        }
        int c1=0, c2=0;
        
        bool flag=false;
        
        
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                if(cnt1[i]<=0 || cnt2[j]<=0)continue;
                cnt1[i]--;
                cnt2[i]++;
                cnt2[j]--;
                cnt1[j]++;
                
                int x=0, y=0;
                
                for(int k=0;k<26;k++){
                    if(cnt1[k]>0)x++;
                    if(cnt2[k]>0)y++;
                }
                
                if(x==y)flag=true;
                
                cnt1[i]++;
                cnt2[i]--;
                cnt2[j]++;
                cnt1[j]--;
            }
        }
        
        return flag;
    }
};