class Solution {
public:
    bool winnerOfGame(string colors) {
        int cnt0=0, cnt1=0;
        for(int i=1;i<colors.size()-1;i++){
            if(colors[i]==colors[i-1] && colors[i]==colors[i+1]){
                if(colors[i]=='A')cnt0++;
                else cnt1++;
            }
        }
        return (cnt0>cnt1);
    }
};