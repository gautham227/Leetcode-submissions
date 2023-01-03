class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            char last='a';
            bool flag=true;
            for(int j=0;j<strs.size();j++){
                if(strs[j][i]<last){
                    flag=false;
                    break;
                }
                else last=strs[j][i];
            }
            if(!flag)ans++;
        }
        return ans;
    }
};