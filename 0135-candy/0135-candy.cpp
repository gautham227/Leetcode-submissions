class Solution {
public:
    int candy(vector<int>& rating) {
        if(rating.size()==1)return 1;
        vector<int> can(rating.size(), 1);
        for(int i=0;i<rating.size();i++){
            if(i==0){
                can[i]+=(rating[i+1]<rating[i]);
                // cout<<can[i]<<" ";
                continue;
            }
            if(rating[i]>rating[i-1]){
                can[i]+=can[i-1];
            }
            else if(i!=rating.size()-1){
                can[i]+=(rating[i+1]<rating[i]);
            }
            // cout<<can[i]<<" ";
        }
        // cout<<endl;
        for(int i=rating.size()-1;i>=0;i--){
            int l=0, r=0;
            if(i!=0 && rating[i]>rating[i-1])l=can[i-1];
            if(i!=rating.size()-1 && rating[i]>rating[i+1])r=can[i+1];
            can[i]=max(l,r)+1;
        }
        return accumulate(can.begin(), can.end(), 0);
    }
};