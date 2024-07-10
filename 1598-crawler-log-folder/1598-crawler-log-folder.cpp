class Solution {
public:
    int minOperations(vector<string>& logs) {
        int cntr=0;
        for(int i=0;i<logs.size();i++){
            if(logs[i][0]=='.' && logs[i][1]=='/')continue;
            else if(logs[i][0]=='.' && logs[i][1]=='.'){
                cntr=max(0, cntr-1);
            }
            else cntr++;
        }
        return cntr;
    }
};