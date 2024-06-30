class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int>v(26);
        for(int i=0;i<letters.size();i++){
            v[letters[i]-'a']++;
        }
        int n=words.size();
        int ans=0;
        for(int i=0;i<(1<<n);i++){
            vector<int> reqd(26, 0);
            int ans1=0;
            for(int k=0;k<n;k++){
                if((i&(1<<k))>0){
                    for(int j=0;j<words[k].size();j++){
                        reqd[words[k][j]-'a']++;
                    }
                }
            }
            bool flag=true;
            for(int i=0;i<26;i++){
                if(v[i]<reqd[i]){
                    flag=false;
                }
            }
            if(flag){
                for(int i=0;i<26;i++){
                    ans1+=score[i]*reqd[i];
                }
                ans=max(ans,ans1);
            }
        }
        return ans;
    }
};