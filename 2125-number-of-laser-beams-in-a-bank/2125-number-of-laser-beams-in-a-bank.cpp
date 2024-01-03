class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans=0;
        int prev=-1;
        for(int i=0;i<bank.size();i++){
            int cnt=0;
            for(int j=0;j<bank[i].size();j++){
                if(bank[i][j]=='1'){
                    cnt++;
                }
            }
            if(cnt<=0)continue;
            if(prev==-1){
                prev = cnt;
            }
            else{
                ans=ans+prev*cnt;
                prev=cnt;
            }
        }
        return ans;
    }
};