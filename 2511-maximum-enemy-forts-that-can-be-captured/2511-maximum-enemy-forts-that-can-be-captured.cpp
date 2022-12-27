class Solution {
public:
    int captureForts(vector<int>& forts) {
        int ans=0;

        int n=forts.size();
        int cur=0;
        for(int i=0;i<n;i++){
            if(forts[i]==1){

                cur=0;
                for(int j=i+1;j<n;j++){
                    if(forts[j]==1)break;
                    else if(forts[j]==-1){
                        ans=max(ans,cur);
                        break;
                    }
                    else{
                        cur++;
                    }
                }

                cur=0;
                for(int j=i-1;j>=0;j--){
                    if(forts[j]==1)break;
                    else if(forts[j]==-1){
                        ans=max(ans,cur);
                        break;
                    }
                    else{
                        cur++;
                    }
                }
            }
        }


        return ans;
    }
};