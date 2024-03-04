class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        multiset<int> ms;
        for(int i=0;i<tokens.size();i++){
            ms.insert(tokens[i]);
        }
        int tok=0;
        int ans=0;
        while(ms.size()>0){
            if((*ms.begin())<=power){
                tok++;
                power-=(*ms.begin());
                ms.erase(ms.begin());
            }
            else{
                if(tok>=1){
                    power+=(*(--ms.end()));
                    ms.erase(--ms.end());
                    tok--;
                }
                else{
                    break;
                }
            }
            ans=max(ans,tok);
        }
        return ans;
    }
};